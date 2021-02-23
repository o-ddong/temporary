#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		get_next_line(int fd, char **line);
int		line_split(char **line, char **backup);
int		return_value(int read_size, char **line, char *backup);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, int len);

#endif