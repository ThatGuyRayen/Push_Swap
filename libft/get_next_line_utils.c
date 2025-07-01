/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:42:25 by tpandya           #+#    #+#             */
/*   Updated: 2025/06/01 17:42:26 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ftt_strjoin(char *s1, const char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		result[i] = s2[j++];
		i++;
	}
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*extract_line(char **buffer)
{
	char	*line;
	char	*new_str;
	int		newline_index;

	newline_index = new_line_finder(*buffer);
	if (newline_index == -1)
		newline_index = ft_strlen(*buffer);
	line = (char *)malloc((newline_index + 2) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strncpy(line, *buffer, newline_index);
	if ((*buffer)[newline_index] == '\n')
		line[newline_index++] = '\n';
	line[newline_index] = '\0';
	new_str = ft_strdup(*buffer + newline_index);
	free(*buffer);
	*buffer = new_str;
	return (line);
}
