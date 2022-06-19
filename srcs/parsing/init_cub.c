/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 02:23:39 by egiacomi          #+#    #+#             */
/*   Updated: 2022/06/19 17:37:26 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_validcub(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W' && c != 'E' \
	&& c != 'F' && c != 'C' && !ft_isspace(c) && c != '\0' )
		return (0);
	return (1);
}

int	check_multicub(t_map *map, char **cub)
{
	int		i;
	int		res;
	char	c;

	i = 0;
	res = 0;
	while (cub[i] && i < map->hc)
	{
		c = cub[i][0];
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E' \
		|| c == 'F' || c == 'C')
			res++;
		i++;
	}
	return (res);
}

void	check_cub(t_map *map, char **cub)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	ret = check_multicub(map, cub);
	if (ret != 6)
		error_parsing(map, "Invalid or missing line in .cub file");
	while (cub[i] && i < map->hc)
	{
		if (is_validcub(cub[i][0]))
			i++;
		else
			error_parsing(map, "Invalid line in .cub file");
	}
}

void	get_size_cub(t_map *map, char *path)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	fd = open(path, O_RDONLY);
	line = NULL;
	if (fd == -1)
		error_parsing(NULL, "The file did not open properly");
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if ((int)ft_strlen(line) > map->wc)
			map->wc = ft_strlen(line);
		free(line);
		map->hc++;
	}
	ft_close(fd);
}

void	fill_cub(t_map *map, char *path)
{
	int		fd;
	int		ret;
	int		i;

	ret = 1;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_parsing(NULL, "The file did not open properly");
	map->cub = ft_calloc(sizeof(char *), map->hc + 2);
	while (ret > 0)
	{
		ret = get_next_line(fd, &map->cub[i]);
		i++;
	}
	map->cub[i] = 0;
	ft_close(fd);
}
