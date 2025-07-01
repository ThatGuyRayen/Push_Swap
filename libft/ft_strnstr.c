/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:38:30 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/11 18:39:02 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const unsigned char	*str;
	const unsigned char	*tofind;
	size_t				i;
	size_t				j;

	str = (const unsigned char *)haystack;
	tofind = (const unsigned char *)needle;
	if (*tofind == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == tofind[j] && tofind[j] != '\0' && (i + j) < len)
			j++;
		if (tofind[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
