/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:51:00 by mamir             #+#    #+#             */
/*   Updated: 2024/02/11 20:51:05 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_rest(char *statik)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!statik)
		return (NULL);
	while (statik[i] != '\n' && statik[i])
		i++;
	if (statik[i] == '\0')
	{
		free(statik);
		return (NULL);
	}
	line = malloc(ft_strlen(statik) - i + 1);
	if (!line)
		return (NULL);
	i++;
	while (statik[i])
		line[j++] = statik[i++];
	line[j] = '\0';
	free(statik);
	return (line);
}

char	*ft_read_line(char *statik)
{
	int		i;
	char	*line;

	i = 0;
	if (!statik[i])
		return (NULL);
	while (statik[i] != '\n' && statik[i] != '\0')
		i++;
	if (statik[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (statik[i] != '\n' && statik[i] != '\0')
	{
		line[i] = statik[i];
		i++;
	}
	if (statik[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *statik)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read != 0 && !ft_strchr(statik, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(statik);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		statik = ft_strjoin(statik, buffer);
	}
	free(buffer);
	return (statik);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*statik[1024];

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	statik[fd] = ft_read(fd, statik[fd]);
	if (!statik[fd])
		return (NULL);
	line = ft_read_line(statik[fd]);
	statik[fd] = ft_rest(statik[fd]);
	return (line);
}
