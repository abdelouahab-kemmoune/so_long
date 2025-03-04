/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:46:04 by akemmoun          #+#    #+#             */
/*   Updated: 2025/02/28 16:46:20 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(left_c), NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!left_c)
			return (NULL);
		if (ft_strchr(left_c, '\n'))
			break ;
	}
	return (left_c);
}

char	*set_line(char *line_buffer)
{
	int		i;
	char	*left_c;

	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == 0)
		return (NULL);
	if (line_buffer[i] == '\n')
		i++;
	left_c = ft_substr(line_buffer, i, ft_strlen(line_buffer) - i);
	if (*left_c == 0)
		return (free(left_c), NULL);
	line_buffer[i] = '\0';
	return (left_c);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*left_c;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)(BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, left_c, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	left_c = set_line(line);
	return (line);
}
