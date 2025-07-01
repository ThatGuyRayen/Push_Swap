/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:38:44 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/11 18:41:34 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	int				i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	if (!s)
		return (NULL);
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)str + i);
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "i don't know what the hell is going oon";
	char	c = 'w';
	printf("%s", ft_strchr(str, c));
	return (0);
	
}*/
