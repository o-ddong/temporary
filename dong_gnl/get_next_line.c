#include "dong_get_next_line.h"

char *tmp1;
char *tmp2;

int line_split(char **line, char *backup)
{
    if (tmp1 = ft_strchr(*backup, '\n'))
    {
        *line = ft_substr(*backup, 0, tmp1 - *backup);
        tmp2 = ft_strdup(tmp1 + 1);
        free(*backup);
        *backup = tmp2;
        return (1);
    }
    else
    {
        *line = ft_strdup("");
        free(*backup);
        *backup = NULL;
        return (0);
    }
}

int return_value(int fd, int read_size, char **line, char **backup)
{
    if (read_size < 0)
        return (-1);
    else if (read_size == 0 && !*backup[fd])
    {
        *line = ft_strdup(*backup[fd]);
        return (0);
    }
    else
        line_split(line, *backup[fd]);
}
int	get_next_line(int fd, char **line)
{
    static char *backup[256];
    char        buf[BUFFER_SIZE + 1];
    char        *tmp;
    int         read_size;

    if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
        return (-1);
    if (*backup[fd] == NULL)
        backup[fd] = ft_strdup("");
    while (tmp = !ft_strchr(backup[fd], '\n') && (read_size = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        backup[read_size] = 0;
        backup[fd] = ft_strjoin(backup[fd], tmp);
    }
    return (return_value(fd, read_size, line, backup);
}