/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:53:44 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/10 13:53:48 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;
typedef struct s_bench
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
	char			*algo;
	float			disorder;
}					t_bench;
int					syntax_error(char *str);
int					duplicate_error(t_stack *a, int n);
void				exit_error(t_stack **a);
int					stack_sorted(t_stack *stack);
void				pa(t_stack **a, t_stack **b, t_bench *count);
void				pb(t_stack **a, t_stack **b, t_bench *count);
void				rra(t_stack **a, t_bench *count);
void				rrb(t_stack **b, t_bench *count);
void				rrr(t_stack **a, t_stack **b, t_bench *count);
void				ra(t_stack **a, t_bench *count);
void				rb(t_stack **b, t_bench *count);
void				rr(t_stack **a, t_stack **b, t_bench *count);
void				stack_init(t_stack **a, char **argv);
void				stack_add_back(t_stack **stack, t_stack *new);
t_stack				*stack_new(int value);
void				free_stack(t_stack **stack);
int					stack_len(t_stack *stack);
void				sa(t_stack **a, t_bench *count);
void				sb(t_stack **b, t_bench *count);
void				ss(t_stack **a, t_stack **b, t_bench *count);
long				ft_atoi(const char *str);
void				simple(t_stack **a, t_stack **b, t_bench *count);
int					node_index(t_stack *a, t_stack *target);
int					strncmp(const char *s1, const char *s2, size_t n);
void				strategy_selector(char *strategy, t_stack **a, t_stack **b,
						t_bench *count);
float				compute_disorder(t_stack **a);
char				**ft_split(char const *s, char c);
int					if_bench(char **argv);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				print_bench(t_bench bench);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				print_results(t_bench bench);
void				radix_sort(t_stack **a, t_stack **b, t_bench *count);
void				stack_index(t_stack *a);
void				selection_sort(int *array, int count);
void				set_index(t_stack *a, int *sorted, int count);
void				fill_array(t_stack *a, int *array);
void				algo_chunk(t_stack **a, t_stack **b, t_bench *bench);
int					index_pos(t_stack *stack, int target);
int					get_index_pos(t_stack *stack, int target_index);
void				putnbr_float_fd(float num, int fd);
#endif
