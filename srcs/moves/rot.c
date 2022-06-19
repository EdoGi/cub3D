/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:28:41 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 03:35:12 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// FIXME : Play with rot var's
void	ft_rot_left(t_map *map)
{
	double		old_dirx;
	double		old_planex;

	old_dirx = map->player.dir.x;
	old_planex = map->player.plane.x;
	map->player.dir.x = map->player.dir.x * cos(-map->player.rt_spd)
		- map->player.dir.y * sin(-map->player.rt_spd);
	map->player.dir.y = old_dirx * sin(-map->player.rt_spd)
		+ map->player.dir.y * cos(-map->player.rt_spd);
	map->player.plane.x = map->player.plane.x * cos(map->player.rt_spd)
		- map->player.plane.y * sin(-map->player.rt_spd);
	map->player.plane.y = old_planex * sin(-map->player.rt_spd)
		+ map->player.plane.y * cos(-map->player.rt_spd);
}

void	ft_rot_right(t_map *map)
{
	double		old_dirx;
	double		old_planex;

	old_dirx = map->player.dir.x;
	old_planex = map->player.plane.x;
	map->player.dir.x = map->player.dir.x * cos(map->player.rt_spd)
		- map->player.dir.y * sin(map->player.rt_spd);
	map->player.dir.y = old_dirx * sin(map->player.rt_spd)
		+ map->player.dir.y * cos(map->player.rt_spd);
	map->player.plane.x = map->player.plane.x * cos(map->player.rt_spd)
		- map->player.plane.y * sin(map->player.rt_spd);
	map->player.plane.y = old_planex * sin(map->player.rt_spd)
		+ map->player.plane.y * cos(map->player.rt_spd);
}

void	ft_rot_up(t_map *map)
{
	if (map->player.look <= WIN_H / 2)
		map->player.look += 20;
}

void	ft_rot_down(t_map *map)
{
	if (map->player.look >= -(WIN_H / 2))
		map->player.look -= 20;
}
