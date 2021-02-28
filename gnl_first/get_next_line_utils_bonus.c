/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gashin <gashin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:54:47 by gashin            #+#    #+#             */
/*   Updated: 2021/02/03 18:48:36 by gashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
		if (!s[i++])
			return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = 0;
	while (str[len])
		++len;
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	j = 0;
	if (start < slen)
	{
		while (i < start + len && s[i] != '\0')
		{
			str[j] = s[i];
			j++;
			i++;
		}
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
	if (p == '\0')
		return (0);
	i = 0;
	while (i < len1 + len2)
	{
		if (i < len1)
			p[i] = s1[i];
		if (i >= len1)
			p[i] = s2[i - len1];
		i++;
	}
	p[i] = '\0';
	return (p);
}
