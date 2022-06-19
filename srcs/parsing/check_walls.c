/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:03:19 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/18 22:11:04 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	check_wallnorth(t_map *map, char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->wm)
	{
		i = 0;
		while (i < map->hm && tab[i])
		{
			while ((ft_isspace(tab[i][j]) || tab[i][j] == 0) && i < map->hm - 1)
				i++;
			if (i < map->hm - 1 && tab[i][j] != '1')
				error_parsing(map, "There is a hole in the north wall");
			i++;
			while (i < map->hm - 1 && (tab[i][j] == '0' || \
			is_perso(tab[i][j]) || ft_isspace(tab[i][j] || tab[i][j] == '1')))
					i++;
		}
		j++;
	}
}

void	check_wallsouth(t_map *map, char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->wm)
	{
		i = map->hm - 1;
		while (i > 0)
		{
			while ((ft_isspace(tab[i][j]) || tab[i][j] == 0) && i > 0)
				i--;
			if (i > 0 && tab[i][j] != '1')
				error_parsing(map, "There is a hole in the south wall");
			i--;
			while (i > 0 && (tab[i][j] == '0' || is_perso(tab[i][j])))
				i--;
		}
		j++;
	}
}

void	check_wallwest(t_map *map, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->hm)
	{
		j = 0;
		while (j < map->wm && j < (int)ft_strlen(tab[i]))
		{
			while ((ft_isspace(tab[i][j]) || tab[i][j] == 0) && j < map->wm)
				j++;
			if (j < map->wm && tab[i][j] != '1')
				error_parsing(map, "There is a hole in the west wall");
			j++;
			while (j < map->wm && (tab[i][j] == '0' || is_perso(tab[i][j])))
				j++;
		}
		i++;
	}
}

void	check_walleast(t_map *map, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->hm)
	{
		j = map->wm - 1;
		while (j > 0)
		{
			while ((ft_isspace(tab[i][j]) || tab[i][j] == 0) && j > 0)
				j--;
			if (j > 0 && tab[i][j] != '1')
				error_parsing(map, "There is a hole in the east wall");
			j--;
			while (j > 0 && (tab[i][j] == '0' || is_perso(tab[i][j])))
				j--;
		}
		i++;
	}
}

void	check_closedmap(t_map *map, char **tab)
{
	check_wallnorth(map, tab);
	check_wallsouth(map, tab);
	check_wallwest(map, tab);
	check_walleast(map, tab);
	check_oneperso(map, tab);
}
