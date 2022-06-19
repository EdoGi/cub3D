/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:45:28 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 16:49:12 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:45:28 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/18 17:38:41 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	*find_text(t_map *map, char *line, char *text)
{
	int		i;
	char	*res;
	int		fd;

	(void)map;
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	res = ft_strdup(line + i);
	fd = open(res, O_RDONLY);
	if (fd < 0 && ft_strlen(text) == 3)
	{
		free(res);
		error_parsing(map, "A texture's path is invalid");
	}
	if (fd > 0)
		ft_close(fd);
	return (res);
}

char	*get_restext(t_map *map, char **cub, char *text, int *state)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	res = NULL;
	while (cub[i] && i < map->hc)
	{
		j = 0;
		while (cub[i][j] && ft_isspace(cub[i][j]))
			j++;
		if (ft_strlen(cub[i] + j) >= 2)
		{
			if (ft_strncmp(cub[i] + j, text, ft_strlen(text)) == 0)
			{
				if (res)
					free(res);
				res = find_text(map, cub[i] + 2, text);
				*state += 1;
			}	
		}
		i++;
	}
	return (res);
}

char	*get_text(t_map *map, char **cub, char *text)
{
	char	*res;
	int		state;

	state = 0;
	res = get_restext(map, cub, text, &state);
	if (state > 1)
	{
		if (res)
			free(res);
		error_parsing(map, "There is more than one path for one texture");
	}
	return (res);
}

void	fill_tex(t_map *map)
{
	init_tex(map, &map->tex.no);
	init_tex(map, &map->tex.so);
	init_tex(map, &map->tex.ea);
	init_tex(map, &map->tex.we);
}
