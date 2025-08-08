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
		return (NULL);
	return (str);
}

static int	parse_number(const char *str, int sign, int *out)
{
	long	result;

	result = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX) 
			|| (sign == -1 && (-result) < INT_MIN))
			return (0);
		str++;
	}
	*out = (int)(result * sign);
	return (1);
}

int	ps_atoi(const char *str, int *res)
{
	int	sign;

	sign = 1;
	if (!str || !res)
		return (0);
	str = skip_spaces_and_sign(str, &sign);
	if (!str)
		return (0);
	if (!parse_number(str, sign, res))
		return (0);
	return (1);
}
