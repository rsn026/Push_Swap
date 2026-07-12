/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:28:30 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/07 18:24:19 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strategy_selector(char *strategy, t_stack **a, t_stack **b,
		t_bench *bench)
{
	stack_index(*a);
	bench->disorder = compute_disorder(a);
	if (strategy && strncmp(strategy, "--simple", 9) && strncmp(strategy,
			"--medium", 9) && strncmp(strategy, "--complex", 10)
		&& strncmp(strategy, "--adaptive", 11))
		exit_error(a);
	if (stack_sorted(*a))
		return ;
	if (strategy && !strncmp(strategy, "--simple", 9))
		simple(a, b, bench);
	else if (strategy && !strncmp(strategy, "--medium", 9))
		algo_chunk(a, b, bench);
	else if (strategy && !strncmp(strategy, "--complex", 10))
		radix_sort(a, b, bench);
	else
	{
		if (bench->disorder < 0.2 || stack_len(*a) <= 5)
			(simple(a, b, bench), bench->algo = "Adaptive / O(n^2)");
		else if (bench->disorder >= 0.2 && bench->disorder < 0.5)
			(algo_chunk(a, b, bench), bench->algo = "Adaptive / O(n√n)");
		else if (bench->disorder >= 0.5)
			(radix_sort(a, b, bench), bench->algo = "Adaptive / O(nlogn)");
	}
}

float	compute_disorder(t_stack **a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	float	mistakes;
	float	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	tmp1 = *a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			total_pairs += 1;
			if (tmp1->value > tmp2->value)
				mistakes += 1;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (mistakes / total_pairs);
}
