/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:06:32 by egiacomi          #+#    #+#             */
/*   Updated: 2022/06/19 16:58:28 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <float.h>

// FIXME : Play with s_dist
void	set_step(t_ray *ray, t_play *player)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->s_dist.x = (player->pos.x - ray->map_x) * ray->d_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->s_dist.x = (ray->map_x + 1.0 - player->pos.x) * ray->d_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->s_dist.y = (player->pos.y - ray->map_y) * ray->d_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->s_dist.y = (ray->map_y + 1.0 - player->pos.y) * ray->d_dist.y;
	}	
}

void	set_deltadist(t_ray *ray)
{
	if (ray->dir.x == 0)
		ray->d_dist.x = INT_MAX;
	else
		ray->d_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->d_dist.y = INT_MAX;
	else
		ray->d_dist.y = fabs(1 / ray->dir.y);
}

// FIXME : Play with sides
void	find_hit(t_map *map, t_ray *ray)
{
	while (ray->hit == FALSE)
	{
		if (ray->s_dist.x < ray->s_dist.y)
		{
			ray->s_dist.x += ray->d_dist.x;
			ray->map_x += ray->step.x;
			if (ray->dir.x > 0)
				ray->side = EA;
			else
				ray->side = WE;
		}
		else
		{
			ray->s_dist.y += ray->d_dist.y;
			ray->map_y += ray->step.y;
			if (ray->dir.y > 0)
				ray->side = SO;
			else
				ray->side = NO;
		}
		if (map->map[ray->map_x][ray->map_y] == '1')
			ray->hit = TRUE;
	}
}

void	ray_loop(t_map *map)
{
	int		px;
	t_ray	*ray;

	px = 0;
	ray = &map->ray;
	while (px < WIN_W)
	{
		ray->cam_x = 2 * px / (double)WIN_W - 1;
		ray->dir.x = map->player.dir.x + map->player.plane.x
			* map->ray.cam_x;
		ray->dir.y = map->player.dir.y + map->player.plane.y
			* map->ray.cam_x;
		ray->map_x = (int)map->player.pos.x;
		ray->map_y = (int)map->player.pos.y;
		set_deltadist(ray);
		set_step(ray, &map->player);
		ray->hit = FALSE;
		find_hit(map, ray);
		find_walldist(map, ray);
		put_to_img(map, px);
		px++;
	}
}

int	dispray(t_map *map)
{
	key_loop(map);
	ray_loop(map);
	create_minimap(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	return (0);
}
