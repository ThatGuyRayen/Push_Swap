/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:26:28 by tpandya           #+#    #+#             */
/*   Updated: 2025/08/08 13:26:30 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*skip_spaces_and_sign(const char *str, int *sign)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		ft_error("Error\n");
	return (str);
}

static long	parse_number(const char *str, int sign)
{
	long	result;

	result = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			ft_error("Error\n");
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX) 
			|| (sign == -1 && (-result) < INT_MIN))
			ft_error("Error\n");
		str++;
	}
	return (result);
}

int	ps_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	str = skip_spaces_and_sign(str, &sign);
	result = parse_number(str, sign);
	return ((int)(result * sign));
}
