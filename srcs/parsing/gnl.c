/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:11:29 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 17:32:31 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	*gnl_strjoin(char *dst, char *src)
{
	char	*joined;
	int		i;
	int		j;
	int		totlen;

	if (!dst)
		return (gnl_strdup(src));
	totlen = gnl_strlen(src) + gnl_strlen(dst);
	joined = (char *)malloc(sizeof(char) * (totlen + 1));
	if (!joined)
		return (NULL);
	i = -1;
	j = 0;
	while (dst[++i])
		joined[i] = dst[i];
	while (src[j])
		joined[i++] = src[j++];
	joined[i] = 0;
	free(dst);
	return (joined);
}

char	*gnl_tonl(char *str)
{
	char	*newline;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	newline = malloc(sizeof(char) * i + 1);
	if (!newline)
		return (NULL);
	newline[i] = '\0';
	while (--i >= 0)
		newline[i] = str[i];
	return (newline);
}

char	*gnl_strchr(char *s, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i++] == (char)c)
			while (s[i])
				s[j++] = s[i++];
	}
	s[j] = '\0';
	return (NULL);
}

int	gnl_return(int ret, char **line, char *mem, char *buf)
{
	if (ret > 0)
	{
		*line = gnl_tonl(mem);
		gnl_strchr(buf, '\n');
		free(mem);
		return (1);
	}
	if (ret == 0)
	{
		*line = gnl_strdup(mem);
		free(mem);
		buf[0] = 0;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	buf[BUFFER_SIZE + 1];
	char		*mem;

	ret = 1;
	mem = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	mem = gnl_strjoin(mem, buf);
	while (is_not_newline(buf) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{	
			free(mem);
			return (-1);
		}
		buf[ret] = '\0';
		mem = gnl_strjoin(mem, buf);
	}
	return (gnl_return(ret, line, mem, buf));
}
