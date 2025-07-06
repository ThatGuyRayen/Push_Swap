/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:02:04 by tpandya           #+#    #+#             */
/*   Updated: 2025/07/06 19:02:05 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_to_arr(t_stack *stack)
{
	int		*arr;
	int		i;
	t_node	*current;

	i = 0;
	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	current = stack->top;
	while (i < stack->size)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	return (arr);
}

int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_index_to_nodes(t_stack *stack, int *sorted_values)
{
	t_node	*current;
	int		i;

	current = stack->top;
	while (current)
	{
		i = find_index(sorted_values, stack->size, current->value);
		current->index = i;
		current = current->next;
	}
}

void	b_sort(int *arr, int size)
{
	int	temp;
	int	swapped;
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
	}
}

void	assign_index(t_stack *stack)
{
	int	*values;
	int	size;

	size = stack->size;
	values = copy_to_arr(stack);
	if (!values)
		return ;
	b_sort(values, size);
	assign_index_to_nodes(stack, values);
	free(values);
}
