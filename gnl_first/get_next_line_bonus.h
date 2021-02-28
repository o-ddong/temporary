/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gashin <gashin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:51:53 by gashin            #+#    #+#             */
/*   Updated: 2021/02/03 18:48:36 by gashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"

int		get_next_line(int fd, char **line);
int		line_split(char **line, char **backup);
int		return_value(int fd, int read_size, char **line, char **backup);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, int len);

#endif
