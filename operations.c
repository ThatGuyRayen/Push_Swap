/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:55:45 by tpandya           #+#    #+#             */
/*   Updated: 2025/07/02 09:55:53 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_s(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	first = stack->top;
	second = first->next;
	stack->top = second;
	first->next = second->next;
	second->next = first;
}

void	push_value(t_stack *stack, int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = value;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

void	push(t_stack *src, t_stack *dest)
{
	t_node	*temp;

	temp = src->top;
	src->top = temp->next;
	src->size--;
	temp->next = dest->top;
	dest->top = temp;
	dest->size++;
}
/*
   1. swap function for swapping elements in same stack
   2. push function for pushing elements from one stack to another
   3. */
