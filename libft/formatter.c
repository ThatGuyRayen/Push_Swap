/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:47:50 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/26 11:47:52 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_char(char c)
{
	return (write(1, &c, 1));
}

int	put_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		count += put_char(*str);
		str++;
	}
	return (count);
}

int	put_nbr(int n)
{
	int		count;
	long	num;

	count = 0;
	num = (long)n;
	if (num < 0)
	{
		count += put_char('-');
		num = -num;
	}
	if (num >= 10)
		count += put_nbr(num / 10);
	count += put_char((num % 10) + '0');
	return (count);
}

char	get_hex_digit(int value, int is_lowercase)
{
	char	*digits;

	if (is_lowercase == 0)
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	return (digits[value % 16]);
}

int	print_hex(unsigned int n, int is_lowercase)
{
	char	buffer[32];
	int		i;
	int		count;

	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	while (n > 0)
	{
		buffer[i++] = get_hex_digit(n % 16, is_lowercase);
		n /= 16;
	}
	count = 0;
	while (--i >= 0)
		count += write(1, &buffer[i], 1);
	return (count);
}
