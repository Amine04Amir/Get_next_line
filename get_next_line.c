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

char *ft_read_line(char *str)
{
	int	i;
	char	*line;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	line[i] = '\0';
	return (line);
}

char *ft_read(int fd, char *s)
{
	char *buffer;
	ssize_t	bytes_read;


	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
	 	bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// if (bytes_read == 0)
		// 	break ;
		buffer[bytes_read] = '\0';
		s = ft_strjoin(s, buffer);
		if (ft_strchr(buffer, '\n')) 
			break ;
	}
	free(buffer);
	return (s);
}

char *get_next_line(int fd)
{
	char *s;
	static char *str;

	if (fd < 0 || BUFFER_SIZE < 0)
		return NULL;
	str = ft_read(fd, s);
	str = ft_readline(str);
	// printf("str = %s\n", str);
	return (str);
}

int main ()
{
    int fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}