/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:37:45 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/07 15:37:48 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	word_length(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] != c && s[count] != '\0')
		count++;
	return (count);
}

static void	free_memory(char **str, int index)
{
	while (index >= 0)
		free(str[index--]);
	free(str);
}

char	*ft__strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;

	str = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !str)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			str[i] = ft_strnew(word_length(s, c));
			if (!(str[i]))
				return (free_memory(str, i - 1), NULL);
			ft__strncpy(str[i], s, word_length(s, c));
			s += word_length(s, c);
			i++;
		}
	}
	str[i] = NULL;
	return (str);
}
