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

#include "get_next_line.h"

void	join_string(char *res, char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
}

char	*ft_readfile(int fd, char *string, char *buffer)
{
	char	*tmp;
	int		buffer_read;

	buffer_read = 1;
	while (buffer_read > 0)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read == -1)
		{
			free(string);
			return (NULL);
		}
		if (buffer_read == 0)
			break ;
		buffer[buffer_read] = '\0';
		if (!string)
			string = ft_strdup("");
		tmp = string;
		string = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (string);
}

char	*ft_freeline(char *string)
{
	char	*line;
	int		i;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\0' || string[1] == '\0')
		return (NULL);
	line = ft_substr(string, i + 1, ft_strlen(string) - i);
	if (*line == 0)
	{
		free(line);
		line = NULL;
	}
	string[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*string;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free(string);
		free(buffer);
		buffer = NULL;
		string = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = ft_readfile(fd, string, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	string = ft_freeline(line);
	return (line);
}
/*
int	main(void)
{
	int fd;
	int count = 0;
	char *next_line;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		printf("[%d]:%s\n", count++, next_line);
		free(next_line);
		next_line = NULL;
	}
	// system("leaks a.out");
	close(fd);
	return (0);
}*/