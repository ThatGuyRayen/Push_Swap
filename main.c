/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:56:16 by tpandya           #+#    #+#             */
/*   Updated: 2025/07/02 09:56:25 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->top)
		return ;
	temp = stack->top;
	while (temp)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	if (argc < 2)
		return (0);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		return (1);
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_b)
	{
		free(stack_a);
		return (1);
	}
	stack_a->top = NULL;
	stack_a->size = 0;
	stack_b->top = NULL;
	stack_b->size = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = count_args(argv);
	}
	fill_stack(stack_a, argc, argv);
	if (stack_a->size < 2)
	{
		free(stack_a);
		free(stack_b);
		return (0);
	}
	print_stack(stack_a);
	ft_printf("\n");
	ra(stack_a);
	print_stack(stack_a);
	return (0);
}
