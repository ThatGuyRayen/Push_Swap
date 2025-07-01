/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:34:30 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/07 15:34:32 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		if (n == INT_MIN)
			return (11);
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*str;

	nb = n;
	len = nb_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (len-- && nb >= 0)
	{
		if (str[len] == '-')
			break ;
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
/*
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int test_cases[] = {0, 123, -123, INT_MAX, INT_MIN, 42, -42};
	int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (int i = 0; i < num_tests; i++)
	{
		char *result = ft_itoa(test_cases[i]);
		if (result)
		{
			printf("ft_itoa(%d) = \"%s\"\n", test_cases[i], result);
			free(result); // Don't forget to free the allocated memory!
		}
		else
		{
			printf("Memory allocation failed for input %d\n", test_cases[i]);
		}
	}

	return (0);
}*/
