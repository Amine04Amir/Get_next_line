#include "get_next_line.h"

#define BUFFER_SIZE 256

// char *next_line()
// {

// }
char	*ft_strjoin(char const *s1, char const *s2)
{
    int i;
    int j;
    char    *joined;

    i = 0;
    j = 0;
    if (!s1 || !s2)
        return (NULL);
    joined = (char *)malloc((ft_strlen(s1)+ft_strlen(s2) + 1) * sizeof(char));
    if (!joined)
        return (NULL);
    while (s1[i])
    {
        joined[i] = s1[i];
        i++;
    }
    while(s2[j])
    {
        joined[i + j] = s2[j];
        j++;
    }
    joined[i + j] = '\0';
    return (joined);
}

char    *get_next_line(int fd)
{
    int bytes_read;
    char *buffer;
    static int count = 1;

    printf("malloc[%d]----", count++);
    buffer = malloc(sizeof(char) * 3+1);
    if (!buffer)
        return (NULL);
    bytes_read = read(fd, buffer, 3);
    if (bytes_read <= 0)
    {
        free (buffer);
        return (NULL);
    }
    return (buffer);
}
int main()
{
    int fd;
    int count = 0;
    char *next_line;
    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        return 1;
    while(1)
    {
        next_line = get_next_line(fd);
        if (next_line == NULL)
            break;
        printf("[%d]:%s\n", count, next_line);
        free(next_line);
        next_line = NULL;
    }
    //system("leaks a.out");
    close(fd);
    return 0;
}