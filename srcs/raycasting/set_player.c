/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:36:48 by egiacomi          #+#    #+#             */
/*   Updated: 2022/06/19 05:57:10 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// FIXME : Play with plane
void	set_plane(t_play *player)
{
	if (player->card == NO || player->card == SO)
	{	
		player->plane.x = 0;
		if (player->card == NO)
			player->plane.y = 0.66;
		else
			player->plane.y = -0.66;
	}
	if (player->card == WE || player->card == EA)
	{	
		player->plane.y = 0;
		if (player->card == EA)
			player->plane.x = 0.66;
		else
			player->plane.x = -0.66;
	}
}

void	set_dir(t_play *player)
{
	if (player->card == NO || player->card == SO)
	{	
		player->dir.y = 0;
		if (player->card == NO)
			player->dir.x = -1;
		else
			player->dir.x = 1;
	}
	if (player->card == WE || player->card == EA)
	{	
		player->dir.x = 0;
		if (player->card == EA)
			player->dir.y = 1;
		else
			player->dir.y = -1;
	}
}

// FIXME : Play with card's
void	find_cardinal(t_map *map, int x, int y)
{
	char	**tab;
	char	card;
	t_play	*player;

	tab = map->map;
	card = tab[x][y];
	player = &map->player;
	if (card == 'N')
		player->card = NO;
	if (card == 'S')
		player->card = SO;
	if (card == 'W')
		player->card = WE;
	if (card == 'E')
		player->card = EA;
	set_dir(player);
}

// FIXME : Play with pos
void	set_pos_dir(t_map *map)
{
	char	**tab;
	int		x;
	int		y;

	x = 0;
	y = 0;
	tab = map->map;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (is_perso(tab[x][y]))
			{
				find_cardinal(map, x, y);
				map->player.pos.x = x + 0.5;
				map->player.pos.y = y + 0.5;
				map->map[x][y] = '0';
				return ;
			}
			y += 1;
		}
		x += 1;
	}
}

// FIXME : Play with spd's
void	set_player(t_map *map)
{
	t_play	*player;

	player = &map->player;
	set_pos_dir(map);
	set_plane(player);
	map->player.mv_spd = 0.08;
	map->player.rt_spd = 0.08;
}
