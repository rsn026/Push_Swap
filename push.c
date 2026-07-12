/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:55:11 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/10 13:55:12 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	*dest = tmp;
}

void	pa(t_stack **a, t_stack **b, t_bench *count)
{
	push(b, a);
	write(1, "pa\n", 3);
	count->pa++;
	count->total++;
}

void	pb(t_stack **a, t_stack **b, t_bench *count)
{
	push(a, b);
	write(1, "pb\n", 3);
	count->pb++;
	count->total++;
}
