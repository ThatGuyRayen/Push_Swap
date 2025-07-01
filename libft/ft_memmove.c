/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:36:58 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/07 15:36:59 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (dest == source || len == 0)
		return (dst);
	if (dest < source)
	{
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		dest = dest + len;
		source = source + len;
		while (len--)
			*(--dest) = *(--source);
	}
	return (dst);
}
