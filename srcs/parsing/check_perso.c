/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_perso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:04:37 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 02:26:36 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	is_perso(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (1);
	return (0);
}

void	check_oneperso(t_map *map, char **tab)
{
	int	i;
	int	j;
	int	state;

	i = 0;
	state = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (is_perso(tab[i][j]))
				state++;
			j++;
		}
		i++;
	}
	if (state != 1)
		error_parsing(map, "Wrong number of starting position");
}

void	find_positionperso(t_map *map, int *i, int *j)
{
	char	**tab;

	tab = map->map;
	while (tab[*i])
	{
		*j = 0;
		while (tab[*i][*j])
		{
			if (is_perso(tab[*i][*j]))
				return ;
			*j += 1;
		}
		*i += 1;
	}
	error_parsing(map, "The perso was not found");
}
