/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:57:33 by tpandya           #+#    #+#             */
/*   Updated: 2025/07/02 09:57:36 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*node;

	if (!stack || !stack->top || !stack->top->next)
		ft_error("Error\n");
	temp = stack->top;
	stack->top = temp->next;
	temp->next = NULL;
	node = stack->top;
	while (node->next)
		node = node->next;
	node->next = temp;
}

/* finding last node and node before last one, detaching last node,
	making last node
   to the old top
   upding the top to last node*/
void	reverse_rotate(t_stack *stack)
{
	t_node	*previous;
	t_node	*current;

	if (!stack || !stack->top || !stack->top->next)
		ft_error("Error\n");
	previous = NULL;
	current = stack->top;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = stack->top;
	stack->top = current;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
