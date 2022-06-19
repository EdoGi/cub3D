/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:55:23 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 02:28:45 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	rgb_to_hex(int r, int g, int b)
{
	int	color;

	color = ((int)(r & 0xff) << 16) + ((int)(g & 0xff) << 8)
		+ (int)(b & 0xff);
	return (color);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
	{
		printf("Error\nThe file did not close properly\n");
		exit(0);
	}
}

int	ft_isspace(int c)
{
	if (!c)
		return (-1);
	if (((signed)c >= 9 && (signed)c <= 13) || (signed)c == 32 || \
	(signed)c == '\n')
		return (1);
	return (0);
}

char	*ft_freedup(char *str, char *str2)
{
	char	*res;

	res = ft_strdup(str);
	free(str2);
	return (str);
}

char	*ft_strduplen(char *s, int len)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!res)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
