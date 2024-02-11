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
    return (new);
}

size_t ft_strlen2(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\n')
    {
        i++;
    }
    return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    int i;
    char *substr;

    i = 0;
    if (!s)
        return (NULL);
    if (len > ft_strlen(s) - start)
        len = ft_strlen(s) - start;
    if (ft_strlen(s) <= start)
        return (ft_strdup(""));
    substr = (char *)malloc((len + 1) * sizeof(char));
    if (!substr)
        return (NULL);
    while(s[start] != '\0' && len > 0)
    {
        substr[i] = s[start];
        i++;
        len--;
        start++;
    }
    substr[i] = '\0';
    return  (substr);
}


