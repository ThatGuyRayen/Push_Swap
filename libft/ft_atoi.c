/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:32:41 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/07 15:32:43 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	parser(const char *s, int sign)
{
	long long	result;

	result = 0;
	while (*s && ft_isdigit(*s))
	{
		if (result > (LLONG_MAX - (*s - '0')) / 10)
		{
			if (sign > 0)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result);
}

int	ft_atoi(const char *s)
{
	int				sign;

	if (!s)
		return (0);
	sign = 1;
	while (*s && ft_iswhitespace(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	return ((int)(parser(s, sign) * sign));
}
/*
#include <stdio.h>
int	main (void)
{
	printf("%d\n", ft_atoi("--213"));
	return (0);
}
*/
