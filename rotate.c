/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:53:54 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/10 13:53:55 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **rt)
{
	t_stack	*first;
	t_stack	*last;

	if (!*rt || !(*rt)->next)
		return ;
	first = *rt;
	last = *rt;
	while (last->next)
		last = last->next;
	*rt = first->next;
	if (*rt)
		(*rt)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}

void	ra(t_stack **a, t_bench *count)
{
	rotate(a);
	write(1, "ra\n", 3);
	count->ra++;
	count->total++;
}

void	rb(t_stack **b, t_bench *count)
{
	rotate(b);
	write(1, "rb\n", 3);
	count->rb++;
	count->total++;
}

void	rr(t_stack **a, t_stack **b, t_bench *count)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	count->rr++;
	count->total++;
}
