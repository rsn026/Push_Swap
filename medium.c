/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:31:17 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/10 13:53:25 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_index(t_stack *b)
{
	int		max;
	t_stack	*tmp;

	max = b->index;
	tmp = b;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

static void	push_chunks_b(t_stack **a, t_stack **b, t_bench *bench)
{
	int	chunk_len;
	int	chunk_max;

	chunk_len = ((stack_len(*a) / 20) + 20);
	chunk_max = chunk_len;
	while (*a)
	{
		if ((*a)->index < chunk_max)
		{
			pb(a, b, bench);
			if ((*b)->index < (chunk_max - (chunk_len / 2)))
				rb(b, bench);
		}
		else
			ra(a, bench);
		if (stack_len(*b) == chunk_max)
			chunk_max += chunk_len;
	}
}

static void	push_chunks_a(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max;
	int	pos;

	while (*b)
	{
		max = max_index(*b);
		pos = get_index_pos(*b, max);
		if (pos <= stack_len(*b) / 2)
		{
			while ((*b)->index != max)
				rb(b, bench);
		}
		else
		{
			while ((*b)->index != max)
				rrb(b, bench);
		}
		pa(a, b, bench);
	}
}

void	algo_chunk(t_stack **a, t_stack **b, t_bench *bench)
{
	bench->algo = "medium / O(n√n)";
	push_chunks_b(a, b, bench);
	push_chunks_a(a, b, bench);
}
