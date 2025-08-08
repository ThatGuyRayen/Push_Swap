/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:55:35 by tpandya           #+#    #+#             */
/*   Updated: 2025/07/02 09:55:37 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(char *error_text)
{
	ft_printf("%s", error_text);
	return (0);
}

void	ft_error_0(t_stack *stack_a, t_stack *stack_b, const char *msg,
		char **str)
{
	if (str)
	{
		free_split(str);
		str = NULL;
	}
	free_stacks(stack_a, stack_b);
	if (msg)
		write(2, msg, strlen(msg));
	exit(EXIT_FAILURE);
}

void	ft_error_1(t_stack *stack_a, t_stack *stack_b, const char *msg)
{
	free_stacks(stack_a, stack_b);
	if (msg)
		write(2, msg, strlen(msg));
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}
