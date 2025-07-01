/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:00:10 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/21 16:00:13 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	formatter(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += put_char((char)va_arg(args, int));
	else if (type == 's')
		count += put_str(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		count += put_nbr(va_arg(args, int));
	else if (type == 'x')
		count += print_hex(va_arg(args, unsigned int), 0);
	else if (type == 'X')
		count += print_hex(va_arg(args, unsigned int), 1);
	else if (type == 'u')
		count += print_big_num(va_arg(args, unsigned int));
	else if (type == '%')
		count += put_char('%');
	else if (type == 'p')
		count += print_p(va_arg(args, void *));
	else
	{
		count += write(1, "%", 1);
		count += write(1, &type, 1);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	if (s == NULL)
		return (-1);
	while (*s)
	{
		if (*s == '%')
			count += formatter(*(++s), args);
		else
			count += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (count);
}
//
// #include <stdio.h>
//
// int	main(void)
// {
// 	int	count1;
// 	int	count2;
// 	count1 =    printf("%y\n");
// 	count2 = ft_printf("%y\n");
// 	printf("%d, %d", count1, count2);
// 	return (0);
// }
