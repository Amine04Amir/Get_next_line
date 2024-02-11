#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
        {
            return ((char *)&s[i]);
        }
        i++;
    }
    if ((char)c == '\0')
        return ((char *)&s[i]);
    return (NULL);
}

char *ft_strdup(const char *s)
{
    int i;
    char    *new;

    i = 0;
    new = ((char *)malloc((sizeof(char) * ft_strlen(s)) + 1));
    if (!new)
    {
        return (NULL);
    }
    while (*s)
    {
        new[i++] = *s++;
    }
    new[i] = '\0';
    retun (new);
}



