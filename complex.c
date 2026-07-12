/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:52:25 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/10 13:52:30 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_bit(t_stack *a)
{
	int	len;
	int	max_bit;

	len = stack_len(a) - 1;
	max_bit = 0;
	while (len > 0)
	{
		max_bit++;
		len = len / 2;
	}
	return (max_bit);
}

void	radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	bit;
	int	i;
	int	len;

	bench->algo = "complex / O(nlogn)";
	bit = 0;
	while (bit < find_max_bit(*a))
	{
		i = 0;
		len = stack_len(*a);
		while (i < len)
		{
			if ((((*a)->index >> bit) & 1))
				ra(a, bench);
			else
				pb(a, b, bench);
			i++;
		}
		while (*b)
			pa(a, b, bench);
		bit++;
	}
}
