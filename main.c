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
		ft_error("No stack");
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
		ft_error("error while freeing");
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

void	sort_and_index(t_stack *a, t_stack *b)
{
	assign_index(a);
	sort_stack(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		count;

	if (argc < 2)
		ft_error("Feed more please");
	if (!init_stacks(&stack_a, &stack_b))
		ft_error("Sorry but can't make stack");
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !*args)
			return (free_stacks(stack_a, stack_b), 1);
		count = count_args(args);
		if (!fill_stack(stack_a, count, args))
			return (free_split(args), free_stacks(stack_a, stack_b), 1);
		free_split(args);
	}
	else if (!fill_stack(stack_a, argc - 1, argv + 1))
		return (free_stacks(stack_a, stack_b), 1);
	if (stack_a->size > 1)
		sort_and_index(stack_a, stack_b);
	return (free_stacks(stack_a, stack_b), 0);
}
