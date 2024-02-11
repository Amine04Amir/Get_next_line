#include "get_next_line.h"

#define BUFFER_SIZE 256

char	*ft_strjoin(char const *s1, char const *s2)
{
    
}

char    *get_next_line(int fd)
{
    char *buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    int bytes_read;
    if (buffer == NULL)
    {
        return NULL;
    }
    bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytes_read == -1)
    {
        return NULL;
    }
    else if (bytes_read == 0)
    {
        free (buffer);
        return NULL;
    }
    buffer[bytes_read] = '\0';
    return buffer;
}
int main()
{
    int fd = open("text.txt", O_RDONLY);
    if (fd == -1)
    {

        return 0;
    }
    char *line;
    while((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free (line);
    }
    close(fd);
    return 0;
}