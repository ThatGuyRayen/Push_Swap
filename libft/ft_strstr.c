/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:39:18 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/07 15:39:20 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const unsigned char	*str;
	const unsigned char	*tofind;
	int					i;
	int					j;

	i = 0;
	str = (const unsigned char *)haystack;
	tofind = (const unsigned char *)needle;
	if (*tofind == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == tofind[j] && tofind[j] != '\0')
			j++;
		if (tofind[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
