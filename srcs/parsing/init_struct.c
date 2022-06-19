/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:51:46 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 16:58:28 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_tray(t_map *map)
{
	t_ray	*ray_init;

	ray_init = &map->ray;
	ray_init->go_ray = TRUE;
	ray_init->cam_x = 0;
	ray_init->hit = FALSE;
	ray_init->map_x = 1;
	ray_init->map_y = 1;
	ray_init->side = 0;
	ray_init->wall_start = 0;
	ray_init->wall_height = 0;
	ray_init->wall_end = 0;
	ray_init->wall_x = 0;
	ray_init->w_dist = 0;
	ray_init->dir.x = 1;
	ray_init->dir.y = 1;
	ray_init->d_dist.x = 0;
	ray_init->d_dist.y = 0;
	ray_init->s_dist.x = 0;
	ray_init->s_dist.y = 0;
	ray_init->step.x = 0;
	ray_init->step.y = 0;
}

void	init_tkey(t_map *map)
{
	t_key	*key_init;

	key_init = &map->key;
	key_init->left = FALSE;
	key_init->right = FALSE;
	key_init->up = FALSE;
	key_init->down = FALSE;
	key_init->rot_l = FALSE;
	key_init->rot_r = FALSE;
	key_init->rot_u = FALSE;
	key_init->rot_d = FALSE;
	key_init->exit = FALSE;
}

void	init_ttex(t_map *map)
{
	t_tex	*tex_init;

	tex_init = &map->tex;
	tex_init->no.img_ptr = NULL;
	tex_init->no.height = 0;
	tex_init->no.width = 0;
	tex_init->no.tex_path = NULL;
	tex_init->so.img_ptr = NULL;
	tex_init->so.height = 0;
	tex_init->so.width = 0;
	tex_init->so.tex_path = NULL;
	tex_init->ea.img_ptr = NULL;
	tex_init->ea.height = 0;
	tex_init->ea.width = 0;
	tex_init->ea.tex_path = NULL;
	tex_init->we.img_ptr = NULL;
	tex_init->we.height = 0;
	tex_init->we.width = 0;
	tex_init->we.tex_path = NULL;
}

void	init_tplayer(t_map *map)
{
	t_play	*player_init;

	player_init = &map->player;
	player_init->card = 0;
	player_init->dir.x = 0;
	player_init->dir.y = 0;
	player_init->pos.x = 0;
	player_init->pos.y = 0;
	player_init->plane.x = 0;
	player_init->plane.y = 0;
	player_init->look = 0;
	player_init->mv_spd = 0;
	player_init->rt_spd = 0;
}

void	init_struct(t_map *map)
{
	map->wc = 0;
	map->hc = 0;
	map->cub = NULL;
	map->f = NULL;
	map->f_color = 0;
	map->c = NULL;
	map->c_color = 0;
	map->wm = 0;
	map->hm = 0;
	map->map = NULL;
	map->img.img_ptr = NULL;
	map->mlx_ptr = NULL;
	map->win_ptr = NULL;
	init_tray(map);
	init_tkey(map);
	init_ttex(map);
	init_tplayer(map);
	return ;
}
