#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H 

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char    *get_next_line(int fd);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *s1);
size_t ft_strlen2(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);


#endif
