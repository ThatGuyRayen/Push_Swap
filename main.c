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

int	init_stacks(t_stack **a, t_stack **b)
{
	int	exit;

	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!*a || !*b)
	{
		free(*a);
		free(*b);
		exit = ft_error("Error\n");
		if (exit == 0)
			return (0);
	}
	(*a)->top = NULL;
	(*a)->size = 0;
	(*b)->top = NULL;
	(*b)->size = 0;
	return (1);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
}

void	sort_and_index(t_stack *a, t_stack *b)
{
	assign_index(a);
	sort_stack(a, b);
}

static void	handle_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	char	**args;
	int		count;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !*args)
			ft_error_0(a, b, "Error\n", args);
		count = count_args(args);
		if (!fill_stack(a, count, args))
			ft_error_0(a, b, "Error\n", args);
		free_split(args);
	}
	else if (!fill_stack(a, argc - 1, argv + 1))
		ft_error_1(a, b, "Error\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!init_stacks(&a, &b))
		return (0);
	handle_args(argc, argv, a, b);
	if (check_sorted(a))
		ft_error_1(a, b, "");
	if (a->size > 1)
		sort_and_index(a, b);
	return (free_stacks(a, b), 0);
}
