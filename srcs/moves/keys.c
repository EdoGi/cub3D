/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:50:21 by egiacomi          #+#    #+#             */
/*   Updated: 2022/06/19 04:58:01 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// FIXME : Play with move var's
void	ft_move_w(t_map *map)
{
	t_play	*player;

	player = &map->player;
	if (map->map[(int)(player->pos.x + player->dir.x * player->mv_spd)]
		[(int)(player->pos.y)] == '0')
		player->pos.x += player->dir.x * player->mv_spd;
	if (map->map[(int)(player->pos.x)][(int)(player->pos.y + player->dir.y
		* player->mv_spd)] == '0')
		player->pos.y += player->dir.y * player->mv_spd;
}

void	ft_move_s(t_map *map, t_play *player)
{
	if (map->map[(int)(player->pos.x - player->dir.x * player->mv_spd)]
	[(int)(player->pos.y)] == '0')
		player->pos.x -= player->dir.x * player->mv_spd;
	if (map->map[(int)(player->pos.x)][(int)(player->pos.y - player->dir.y
		* player->mv_spd)] == '0')
		player->pos.y -= player->dir.y * player->mv_spd;
}

void	ft_move_a(t_map *map, t_play *player)
{
	if (map->map[(int)(player->pos.x + player->plane.x
			* player->mv_spd)][(int)(player->pos.y)] == '0')
		player->pos.x += player->plane.x * player->mv_spd;
	if (map->map[(int)(player->pos.x)][(int)(player->pos.y + player->plane.y
		* player->mv_spd)] == '0')
		player->pos.y += player->plane.y * player->mv_spd;
}

void	ft_move_d(t_map *map, t_play *player)
{
	if (map->map[(int)(player->pos.x - player->plane.x
			* player->mv_spd)][(int)(player->pos.y)] == '0')
		player->pos.x += -(player->plane.x * player->mv_spd);
	if (map->map[(int)(player->pos.x)][(int)(player->pos.y - player->plane.y *
	player->mv_spd)] == '0')
		player->pos.y += -(player->plane.y * player->mv_spd);
}

int	key_loop(t_map *map)
{
	if (map->key.up == TRUE)
		ft_move_w(map);
	if (map->key.down == TRUE)
		ft_move_s(map, &map->player);
	if (map->key.left == TRUE)
		ft_move_d(map, &map->player);
	if (map->key.right == TRUE)
		ft_move_a(map, &map->player);
	if (map->key.rot_l == TRUE)
		ft_rot_right(map);
	if (map->key.rot_r == TRUE)
		ft_rot_left(map);
	if (map->key.rot_u == TRUE)
		ft_rot_up(map);
	if (map->key.rot_d == TRUE)
		ft_rot_down(map);
	if (map->key.exit == TRUE)
		handle_esc(map);
	if (map->key.up == FALSE && map->key.down == FALSE
		&& map->key.left == FALSE && map->key.right == FALSE
		&& map->key.rot_l == FALSE && map->key.rot_r == FALSE)
		return (0);
	return (1);
}
