/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gashin <gashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:26:32 by gashin            #+#    #+#             */
/*   Updated: 2021/02/03 17:49:42 by gashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_split(char **line, char **backup)
{
	char	*tmp1;
	char	*tmp2;

	if ((tmp1 = ft_strchr(*backup, '\n')))
	{
		*line = ft_substr(*backup, 0, tmp1 - *backup);
		tmp2 = ft_strdup(tmp1 + 1);
		free(*backup);
		*backup = tmp2;
	}
	else
	{
		*line = ft_strdup(*backup);
		free(*backup);
		*backup = NULL;
		return (0);
	}
	return (1);
}

int	return_value(int fd, int read_size, char **line, char **backup)
{
	if (read_size < 0)
		return (-1);
	else if (read_size == 0 && !*backup[fd])
	{
		free(backup[fd]);
		*line = ft_strdup("");
		return (0);
	}
	else
		return (line_split(line, &backup[fd]));
}

int	get_next_line(int fd, char **line)
{
	static char	*backup[256];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			read_size;

	read_size = 0;
	if (fd < 0 || fd >= 256 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (backup[fd] == NULL)
		backup[fd] = ft_strdup("");
	while (!ft_strchr(backup[fd], '\n')
			&& (read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		tmp = ft_strjoin(backup[fd], buf);
		free(backup[fd]);
		backup[fd] = tmp;
	}
	return (return_value(fd, read_size, line, backup));
}
