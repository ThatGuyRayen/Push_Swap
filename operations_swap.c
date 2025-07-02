/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:57:12 by tpandya           #+#    #+#             */
/*   Updated: 2025/07/02 09:57:15 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	swap_s(stack_a);
}

void	sb(t_stack *stack_b)
{
	swap_s(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_s(stack_a);
	swap_s(stack_b);
}

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
}
