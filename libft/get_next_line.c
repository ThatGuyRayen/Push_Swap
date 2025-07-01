/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:42:19 by tpandya           #+#    #+#             */
/*   Updated: 2025/06/01 17:42:20 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	new_line_finder(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	read_into_buffer(int fd, char **str)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), -1);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		*str = ftt_strjoin(*str, buffer);
		if (!*str)
			return (free(buffer), -1);
		if (new_line_finder(*str) != -1)
			break ;
	}
	free(buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	bytes = read_into_buffer(fd, &str);
	if (ft_strlen(str) == 0 || bytes == -1 || !str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = extract_line(&str);
	if (!line)
	{
		free(str);
		str = NULL;
	}
	return (line);
}
//
// int	main(void)
// {
// 	int		fd;
// 	char	*line;
//
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(42)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
//  	close(fd);
//  	return (0);
//  }
