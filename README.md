# push_swap

A C program that sorts a stack of integers using two stacks and a restricted
set of operations, aiming to do it in as few moves as possible. Rather than
relying on a single sorting strategy, this implementation ships **four**
interchangeable algorithms — three fixed-complexity strategies plus an
adaptive one that picks its approach based on how "disordered" the input is.

## Overview

`push_swap` receives a list of integers as command-line arguments and loads
them into stack `a`. A second stack, `b`, starts empty. The program then
prints, to standard output, the exact sequence of operations needed to sort
`a` in ascending order using only the following moves:

| Operation | Effect |
|-----------|--------|
| `sa` / `sb` / `ss` | Swap the top two elements of `a`, `b`, or both |
| `pa` / `pb` | Push the top of `b` onto `a`, or the top of `a` onto `b` |
| `ra` / `rb` / `rr` | Rotate `a`, `b`, or both up (top becomes bottom) |
| `rra` / `rrb` / `rrr` | Reverse-rotate `a`, `b`, or both (bottom becomes top) |

No data structure other than these two stacks is available — sorting has to
happen entirely through pushes, swaps, and rotations, which makes the choice
of algorithm and its complexity very tangible.

## How sorting is done

Internally, every stack node is annotated with a **rank index** (its position
in the fully sorted order) via `stack_index()`. All four strategies operate
on these ranks rather than the raw values, which keeps the algorithms
value-agnostic.

### 1. Simple — `O(n²)`
`simple.c` repeatedly scans stack `a` for its current minimum, rotates it to
the top by the shortest path (`ra` or `rra`, whichever is closer), and pushes
it onto `b`. Once two elements remain in `a`, a single `sa` fixes their order
if needed, then everything is pushed back from `b` to `a`.

### 2. Medium — `O(n√n)`
`medium.c` implements a chunk-based partition. Stack `a` is split into
buckets of roughly `√n` elements each; each chunk is pushed onto `b` and
locally rotated into place, then chunks are pushed back onto `a` in order by
repeatedly extracting the current chunk's maximum rank from `b`.

### 3. Complex — `O(n log n)`
`complex.c` is a stack-based **radix sort** (LSD, bit by bit) over the rank
indices. For each bit position, elements are partitioned between `a` and `b`
based on that bit, then merged back — `⌈log₂ n⌉` passes over the data.

### 4. Adaptive (default)
`select_flag.c` measures the stack's **disorder** before doing anything (see
below) and dispatches to whichever of the three strategies above fits the
required complexity budget for that disorder level:

| Disorder | Regime | Strategy used |
|----------|--------|----------------|
| `< 0.2` (or `n ≤ 5`) | Low  | Simple — `O(n²)` |
| `0.2 – 0.5` | Medium | Chunk-based — `O(n√n)` |
| `≥ 0.5` | High | Radix — `O(n log n)` |

### Disorder metric

Disorder is a value between `0` (already sorted) and `1` (worst-case order),
computed by counting inversions — pairs `(i, j)` with `i < j` but
`a[i] > a[j]` — and normalizing by the total number of pairs:

```
disorder = inversions / (n * (n - 1) / 2)
```

It is always computed **before** any operation is performed, on the raw
input order.

## Building

```bash
make        # builds the push_swap binary
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + all
```

Compiled with `cc -Wall -Wextra -Werror`. No relinking occurs on repeated
`make` calls.

## Usage

```bash
./push_swap [strategy-flag] [--bench] <int> <int> ...
```

- Arguments can be passed as separate tokens or as a single space-separated
  string (both `./push_swap 2 1 3` and `./push_swap "2 1 3"` work).
- If no arguments are given, the program does nothing and returns
  immediately.
- If the stack is already sorted, no operations are printed.
- On invalid input (non-integer tokens, values outside the 32-bit integer
  range, or duplicate values), the program prints `Error` to stderr and
  exits with a non-zero status.

### Strategy flags

| Flag | Forces |
|------|--------|
| *(none)* | Adaptive strategy (default) |
| `--simple` | `O(n²)` algorithm |
| `--medium` | `O(n√n)` algorithm |
| `--complex` | `O(n log n)` algorithm |
| `--adaptive` | Adaptive strategy, explicitly |

### Benchmark mode

Passing `--bench` (in any position among the flags) prints diagnostics to
**stderr** after sorting, leaving stdout clean for the operation stream:

```bash
$ ./push_swap --bench --simple 5 4 3 2 1 2> bench.log
$ cat bench.log
[bench] disorder: 100.00%
[bench] strategy: Simple / O(n^2)
[bench] total_ops: 10
[bench] sa: 1 sb: 0 ss: 0 pa: 3 pb: 3
[bench] ra: 0 rb: 0 rr: 0 rra: 3 rrb: 0 rrr: 0
```

It reports the measured disorder, the strategy that was actually used (name
+ complexity class), the total operation count, and a per-operation
breakdown.

> **Known limitation:** `--bench` on a stack of a single element currently
> prints a garbage disorder value (division by zero in the disorder
> calculation). Sorting itself is unaffected; only the diagnostic output is
> wrong in this edge case.

### Examples

```bash
$ ./push_swap 2 1 3 6 5 8
ra
pb
rra
pb
pb
ra
pb
sa
pa
pa
pa
pa

$ ./push_swap --medium 4 67 3 87 23 | wc -l
9

$ shuf -i 0-9999 -n 500 | xargs ./push_swap | wc -l
5811
```

## Project structure

```
.
├── Makefile
├── push_swap.h          # shared types (t_stack, t_bench) and prototypes
├── push_swap.c           # entry point: argument parsing, strategy dispatch
├── select_flag.c         # strategy selection + disorder computation
├── simple.c               # O(n²) strategy
├── medium.c               # O(n√n) chunk-based strategy
├── complex.c              # O(n log n) radix strategy
├── algorithm_utils.c      # rank indexing (stack_index, selection_sort, ...)
├── push.c / swap.c / rotate.c / reverse_rotate.c   # the 11 stack operations
├── stack_utils.c          # stack construction and helpers
├── is_sort.c              # sorted-check
├── check_if_error.c       # input validation & error handling
├── split.c                # minimal string-splitting helpers
├── utils.c                # small libc-independent utilities (atoi, strlen, ...)
└── bench.c                # --bench diagnostics output
```

## Design notes

- **No global state.** All counters and the disorder value are threaded
  through a `t_bench` struct passed by pointer, and the stacks are
  doubly-linked lists (`t_stack`) passed by double pointer.
- **Complexity is measured in operations, not comparisons.** Each strategy's
  claimed complexity class refers to the number of `push_swap` operations it
  emits as a function of `n`, not the cost model of a classical array sort.
- **Rank-based logic.** Sorting decisions are made against integer rank
  indices assigned once up front, so the same rotation/partition logic works
  regardless of the actual magnitude or sign of the input values.

## Requirements / constraints

- Written in C, no external sorting libraries.
- Only `read`, `write`, `malloc`, `free`, and `exit` are used as system/libc
  calls; string/number helpers (`ft_atoi`, `ft_split`, `ft_strlen`, `strncmp`,
  etc.) are implemented locally.
- 32-bit signed integers only; out-of-range or duplicate values are rejected.
