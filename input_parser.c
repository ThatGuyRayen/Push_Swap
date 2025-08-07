/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:58:14 by tpandya           #+#    #+#             */
/*   Updated: 2025/07/02 09:58:15 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew_ps(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ft_error("Error\n");
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

int	exits_in_stack(t_stack *stack, int value)
{
	t_node	*temp;

	temp = stack->top;
	while (temp)
	{
		if (temp->value == value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_lstadd_back_ps(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		ft_error("Error\n");
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	fill_stack(t_stack *stack, t_stack *stack_b, int argc, char **argv)
{
	int		i;
	long	value;
	t_node	*node;

	i = 0;
	while (i < argc)
	{
		if (!argv[i] || is_numeric(argv[i]) == 0)
			ft_error_0(stack, stack_b, "Error\n");
		value = ps_atoi(argv[i]);
		if (exits_in_stack(stack, (int)value))
			ft_error_0(stack, stack_b, "Error\n");
		node = ft_lstnew_ps(value);
		if (!node)
			ft_error_0(stack, stack_b, "Error\n");
		node->index = -1;
		ft_lstadd_back_ps(&stack->top, node);
		stack->size++;
		i++;
	}
	return (1);
}

/*
   1. reads and validates input
   2. checks for duplicates and valid integer range
   3. create nodes for each number and building the stack via linked list
   4. stores linked lists inside our 'top' pointer in struct
   */
