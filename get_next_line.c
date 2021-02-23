#include "get_next_line.h"

int                 word_split(char **line, char *backup)
{
    char            *tmp1;

    if (tmp1 = ft_strchr(backup, '\n'))
    {
        *line = ft_substr(backup, 0, tmp1 - backup);
        tmp1 = ft_strdup(tmp1 + 1);
        free(backup);
        backup = tmp1;
    }
    else
    {
        *line = ft_strdup(backup);
        free(backup);
        backup = NULL;
        return (0);
    }
    return (1);
}

int                 return_value(int read_size, char **line, char *backup)
{
    if (read_size < 0)
        return (-1);
    else if (read_size == 0 && !*backup)
    {
        free(backup);
        *line = ft_strdup("");
        return (0);
    }
    else
        return (word_split(line, backup));
}

int	                get_next_line(int fd, char **line)
{
    static char     *backup[1024];
    char            buf[BUFFER_SIZE + 1];
    int             read_size;

    if (fd < 0 || BUFFER_SIZE < 1 || line == NULL)
        return (-1);
    if (backup[fd] == NULL)
        backup[fd] = ft_strdup("");
    while (!ft_strchr(backup[fd], 'n') 
            && (read_size = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[read_size] = 0;
        backup[fd] = ft_strjoin(backup[fd], buf);
    }
    return (return_value(read_size, line, backup[fd]));
}