/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:39:26 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/11 18:39:28 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	char			*last;
	unsigned char	ch;

	ch = (unsigned char)c;
	str = (char *)s;
	last = NULL;
	while (*str)
	{
		if (*str == ch)
			last = str;
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return ((char *)last);
}
