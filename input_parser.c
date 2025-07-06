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
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

int	exits_in_stack(t_stack *stack, int value)
{
	int		i;
	t_node	*temp;

	temp = stack->top;
	i = 0;
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
		return ;
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

int	fill_stack(t_stack *stack, int argc, char **argv)
{
	int		i;
	long	value;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		if (!argv[i])
			return (0); // Invalid input

		value = ft_atoi(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			ft_error("feed me but not too much");

		if (exits_in_stack(stack, (int)value))
			ft_error("Already Exists");

		node = ft_lstnew_ps(value);
		if (!node)
			ft_error("Malloc Failed");

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
