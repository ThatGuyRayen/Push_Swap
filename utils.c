/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:57:00 by tpandya           #+#    #+#             */
/*   Updated: 2025/07/02 09:57:01 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char **argv)
{
	int	count;

	count = 0;
	while (argv[count])
		count++;
	return (count);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	//free(split);
}

int	check_sorted(t_stack *stack)
{
	t_node *current;
	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}



int	ps_atoi(const char *str)
{
	long	result = 0;
	int		sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	if (*str < '0' || *str > '9')
		ft_error("Error\n");
	while (*str)
	{
		if (*str < '0' || *str > '9')
			ft_error("Error\n");
		result = result * 10 + (*str - '0');
		if (sign == 1 && result > INT_MAX)
			ft_error("Error\n");
		if (sign == -1 && -result < INT_MIN)
			ft_error("Error\n");
		str++;
	}

	return ((int)(result * sign));
}
