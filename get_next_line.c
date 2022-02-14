/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:04:17 by tmasur            #+#    #+#             */
/*   Updated: 2022/02/14 22:42:47 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*gnl_buffer;
	char		*line;

	gnl_buffer = fill_buffer(fd, gnl_buffer);
	if (!gnl_buffer)
		return (NULL);
	line = get_line(gnl_buffer);
	gnl_buffer = get_new_buffer_ptr(gnl_buffer);
	return (line);
}

char	*fill_buffer(int fd, char *buffer)
{
	char	*tmp;
	int		bytes_read;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp);
			return (NULL);
		}
		*(tmp + bytes_read) = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*tmp;
	int		i;

	if (!*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		tmp = malloc(i + 2);
	else
		tmp = malloc(i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		tmp[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		tmp[i++] = '\n';
	tmp[i] = '\0';
	return (tmp);
}

char	*get_new_buffer_ptr(char *buffer)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = malloc(ft_strlen(buffer) - i + 1);
	if (!tmp)
		return (NULL);
	j = 0;
	i++;
	while (buffer[i])
		tmp[j++] = buffer[i++];
	tmp[j] = '\0';
	free(buffer);
	return (tmp);
}
