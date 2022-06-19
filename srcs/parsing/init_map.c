/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:14:27 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 17:35:54 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	gnl_lengthmap(t_map *map, int fd)
{
	int		ret;
	char	*line;

	ret = 1;
	line = ft_strdup("");
	while (!is_validmap(line) && ret > 0)
	{	
		free(line);
		ret = get_next_line(fd, &line);
	}
	map->hm = 1;
	while (ret > 0 && is_validmap(line))
	{
		if ((int)ft_strlen(line) > map->wm)
			map->wm = ft_strlen(line);
		map->hm++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	free(line);
	line = NULL;
	return (ret);
}

void	get_lengthmap(t_map *map, char *path)
{
	int		fd;
	int		ret;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_parsing(map, "The file did not open properly");
	ret = gnl_lengthmap(map, fd);
	ft_close(fd);
	if (ret != 0)
		error_parsing(map, "There is an incorrect line in the map");
}

void	gnl_buildmap(t_map	*map, int fd)
{
	char	*line;
	int		ret;
	int		i;

	ret = 1;
	line = NULL;
	i = 0;
	while (!is_validmap(line) && ret > 0)
	{
		if (line)
			free(line);
		ret = get_next_line(fd, &line);
	}
	map->map[i++] = ft_strduplen(line, map->wm);
	free(line);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		map->map[i] = ft_strduplen(line, map->wm);
		free(line);
		i++;
	}
	map->map[i] = NULL;
}

void	build_map(t_map *map, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_parsing(map, "The file did not open properly");
	map->map = ft_calloc(sizeof(char *), map->hm + 1);
	gnl_buildmap(map, fd);
	ft_close(fd);
}

void	fill_map(t_map *map, char *path)
{
	get_lengthmap(map, path);
	if (map->hm < 1 || map->wm < 1)
		error_parsing(map, "The map is invalid");
	build_map(map, path);
	check_closedmap(map, map->map);
}
