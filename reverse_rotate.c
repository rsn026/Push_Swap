/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:52:50 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/10 13:52:52 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **rrt)
{
	t_stack	*last;

	if (!*rrt || !(*rrt)->next)
		return ;
	last = *rrt;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *rrt;
	(*rrt)->prev = last;
	*rrt = last;
}

void	rra(t_stack **a, t_bench *count)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	count->rra++;
	count->total++;
}

void	rrb(t_stack **b, t_bench *count)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	count->rrb++;
	count->total++;
}

void	rrr(t_stack **a, t_stack **b, t_bench *count)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	count->rrr++;
	count->total++;
}
