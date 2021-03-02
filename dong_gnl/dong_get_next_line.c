#include "dong_get_next_line.h"

int	get_next_line(int fd, char **line)
{
    char    *backup[256];
    char    *buf[BUFFER_SIZE + 1];
    char    *tmp;
    int     read_size;

    if (fd < 1 || BUFFER_SIZE < 1 || line == NULL)
        return (-1);
    if (backup[fd] == NULL)
        backup[fd] = ft_strdup("");
    while (!(ft_strchr(backup[fd], '\n')) 
            && read_size = read(fd, buf, BUFFER_SIZE) > 0)
    {
        
    }
}