/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:50:06 by dapereir          #+#    #+#             */
/*   Updated: 2022/11/28 12:31:20 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (NULL);
}

static int	gnl_read_more(char **store, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*new_store;
	int		buffer_size;

	buffer_size = read(fd, buffer, BUFFER_SIZE);
	if (buffer_size > 0)
	{
		buffer[buffer_size] = '\0';
		new_store = ft_strjoin(*store, buffer);
		if (!new_store)
			return (-1);
		gnl_free(store);
		*store = new_store;
	}
	return (buffer_size);
}

static char	*gnl_extract_line(char **store, char *breakline)
{
	char	*line;
	char	*new_store;

	if (!*store)
		return (NULL);
	if (!breakline)
	{
		line = *store;
		*store = NULL;
		if (ft_strlen(line) == 0)
			return (gnl_free(&line));
		return (line);
	}
	line = ft_strndup(*store, breakline - *store + 1);
	if (!line)
		return (gnl_free(store));
	new_store = ft_strdup(breakline + 1);
	if (!new_store)
	{
		gnl_free(&line);
		return (gnl_free(store));
	}
	gnl_free(store);
	*store = new_store;
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*store[OPEN_MAX];
	char			*breakline;
	int				buffer_size;
	char			*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (!store[fd])
		store[fd] = ft_strdup("");
	if (!store[fd])
		return (NULL);
	breakline = ft_strchr(store[fd], '\n');
	buffer_size = 1;
	while (!breakline && buffer_size > 0)
	{
		buffer_size = gnl_read_more(store + fd, fd);
		if (buffer_size == -1)
			return (gnl_free(store + fd));
		breakline = ft_strchr(store[fd], '\n');
	}
	line = gnl_extract_line(store + fd, breakline);
	return (line);
}
