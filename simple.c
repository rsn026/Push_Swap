/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:52:55 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/10 13:52:56 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_min_node(t_stack *a)
{
	t_stack	*min_node;
	int		min;

	if (a == NULL)
		return (NULL);
	min = a->value;
	min_node = a;
	a = a->next;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			min_node = a;
		}
		a = a->next;
	}
	return (min_node);
}

void	simple(t_stack **a, t_stack **b, t_bench *count)
{
	t_stack	*min_node;
	int		len;
	int		index;

	count->algo = "Simple / O(n^2)";
	while (stack_len(*a) > 2)
	{
		min_node = find_min_node(*a);
		index = get_index_pos(*a, min_node->index);
		len = stack_len(*a);
		if (index <= len / 2)
			while (*a != min_node)
				ra(a, count);
		else
			while (*a != min_node)
				rra(a, count);
		pb(a, b, count);
	}
	if ((*a)->value > (*a)->next->value)
		sa(a, count);
	while (*b)
		pa(a, b, count);
}
