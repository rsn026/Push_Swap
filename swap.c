/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:53:01 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/10 13:53:03 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **swp)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*swp && (*swp)->next))
		return ;
	first = *swp;
	second = (*swp)->next;
	*swp = second;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
}

void	sa(t_stack **a, t_bench *count)
{
	swap(a);
	write(1, "sa\n", 3);
	count->sa++;
	count->total++;
}

void	sb(t_stack **b, t_bench *count)
{
	swap(b);
	write(1, "sb\n", 3);
	count->sb++;
	count->total++;
}

void	ss(t_stack **a, t_stack **b, t_bench *count)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	count->ss++;
	count->total++;
}
