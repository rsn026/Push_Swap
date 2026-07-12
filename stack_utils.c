/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:55:16 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/10 13:55:17 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_matrix(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	stack_init(t_stack **a, char **argv)
{
	long	n;
	int		i;
	int		j;
	char	**split_argv;

	i = 0;
	while (argv[i])
	{
		split_argv = ft_split(argv[i], ' ');
		if (!split_argv[0])
			(free_matrix(split_argv), exit_error(a));
		j = 0;
		while (split_argv[j])
		{
			if (syntax_error(split_argv[j]))
				(free_matrix(split_argv), exit_error(a));
			n = ft_atoi(split_argv[j]);
			if (n > INT_MAX || n < INT_MIN || duplicate_error(*a, (int)n))
				(free_matrix(split_argv), exit_error(a));
			stack_add_back(a, stack_new((int)n));
			j++;
		}
		free_matrix(split_argv);
		i++;
	}
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!stack || !new)
		return ;
	temp = *stack;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = new;
			new->prev = temp;
			return ;
		}
		temp = temp->next;
	}
}

t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	stack_len(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 1;
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
