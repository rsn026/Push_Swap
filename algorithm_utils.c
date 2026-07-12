/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:52:14 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/10 13:52:17 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_pos(t_stack *stack, int target_index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	stack_index(t_stack *a)
{
	int	count;
	int	*array;

	if (!a)
		return ;
	count = stack_len(a);
	array = malloc(sizeof(int) * (count));
	if (!array)
		return ;
	fill_array(a, array);
	selection_sort(array, count);
	set_index(a, array, count);
	free(array);
}

void	selection_sort(int *array, int count)
{
	int	i;
	int	j;
	int	index;
	int	tmp;

	i = 0;
	while (i < count - 1)
	{
		index = i;
		j = i + 1;
		while (j < count)
		{
			if (array[j] < array[index])
				index = j;
			j++;
		}
		tmp = array[i];
		array[i] = array[index];
		array[index] = tmp;
		i++;
	}
}

void	set_index(t_stack *a, int *sorted, int count)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	if (!tmp)
		return ;
	while (tmp)
	{
		i = 0;
		while (i < count)
		{
			if (sorted[i] == tmp->value)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	fill_array(t_stack *a, int *array)
{
	int	i;

	i = 0;
	while (a)
	{
		array[i] = a->value;
		i++;
		a = a->next;
	}
}
