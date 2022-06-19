/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:52:07 by egiacomi          #+#    #+#             */
/*   Updated: 2022/06/19 16:58:16 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// TODO : Comprendre mieux cette fonction ; Pourquoi pos.y si side EA/WE ?
void	find_wall_x(t_map *map)
{
	if (map->ray.side == EA || map->ray.side == WE)
		map->ray.wall_x = map->player.pos.y + map->ray.w_dist
			* map->ray.dir.y;
	else
		map->ray.wall_x = map->player.pos.x + map->ray.w_dist
			* map->ray.dir.x;
	map->ray.wall_x -= floor(map->ray.wall_x);
}

// TODO : Comprendre mieux cette fonction ; Pourquoi start = - et end = +
void	wall_height(t_map *map, t_ray *ray)
{
	ray->wall_height = (int)(WIN_H / ray->w_dist);
	ray->wall_start = -(ray->wall_height) / 2 + WIN_H / 2 + map->player.look;
	ray->wall_end = ray->wall_height / 2 + WIN_H / 2 + map->player.look;
	find_wall_x(map);
}

// FIXME : Play with w_dist
void	find_walldist(t_map *map, t_ray *ray)
{
	if (ray->side == WE || ray->side == EA)
		ray->w_dist = (ray->map_x - map->player.pos.x
				+ (1 - ray->step.x) / 2) / ray->dir.x;
	else if (ray->side == NO || ray->side == SO)
		ray->w_dist = (ray->map_y - map->player.pos.y
				+ (1 - ray->step.y) / 2) / ray->dir.y;
	wall_height(map, ray);
}
