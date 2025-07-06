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

int	init_stacks(t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!*a || !*b)
	{
		free(*a);
		free(*b);
		return (0);
	}
	(*a)->top = NULL;
	(*a)->size = 0;
	(*b)->top = NULL;
	(*b)->size = 0;
	return (1);
}

int	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!init_stacks(&stack_a, &stack_b))
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv || !*argv)
			return (free_stacks(stack_a, stack_b), 1);
		argc = count_args(argv);
	}
	if (!fill_stack(stack_a, argc, argv))
		return (free_stacks(stack_a, stack_b), 1);
	if (stack_a->size < 2)
		return (free_stacks(stack_a, stack_b), 0);
	assign_index(stack_a);
	sort_stack(stack_a, stack_b);
	return (free_stacks(stack_a, stack_b), 0);
}
