/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:11:55 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/07 16:12:07 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;

	ptr = (char *)malloc ((ft_strlen(src) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, src);
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str1[] = "hello";
	char	*dest;
	dest = ft_strdup(str1);
	printf("%s", dest);
	free(dest);
	return (0);
}
*/
