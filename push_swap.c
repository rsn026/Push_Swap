/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:26:41 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/10 13:52:44 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	char	*flag;
	int		i;

	bench = (t_bench){0};
	i = 1;
	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	flag = NULL;
	while (argv[i] && strncmp(argv[i], "--", 2) == 0)
	{
		if (strncmp(argv[i], "--bench", 7) != 0)
			flag = argv[i];
		i++;
	}
	stack_init(&a, argv + i);
	strategy_selector(flag, &a, &b, &bench);
	free_stack(&a);
	if (if_bench(argv))
		print_bench(bench);
	return (0);
}
