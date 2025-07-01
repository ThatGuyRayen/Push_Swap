/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:52:33 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/25 12:52:36 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_big_num(unsigned int n)
{
	int				count;
	unsigned int	num;

	count = 0;
	num = n;
	if (num >= 10)
		count += print_big_num(num / 10);
	count += put_char((num % 10) + '0');
	return (count);
}

int	print_p_helper(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += print_p_helper(n / 16);
	count += put_char(hex[n % 16]);
	return (count);
}

int	print_p(void *ptr)
{
	unsigned long	apd;
	int				count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	apd = (unsigned long)ptr;
	count = 0;
	count += write(1, "0x", 2);
	count += print_p_helper((unsigned long)apd);
	return (count);
}
