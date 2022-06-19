/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:34:08 by egiacomi          #+#    #+#             */
/*   Updated: 2022/06/19 16:58:28 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_player(t_play *player)
{
	printf("Player is at [%f ; %f]\n", player->pos.x, player->pos.y);
	printf("Player is looking %d => [%f ; %f]\n", \
		player->card, player->dir.x, player->dir.y);
	printf("Plane is [%f ; %f]\n", player->plane.x, player->plane.y);
}

void	print_ray(t_ray *ray)
{
	printf("cam_x is %f\n", ray->cam_x);
	printf("RayDir is at [%f ; %f]\n", ray->dir.x, ray->dir.y);
	printf("Ray Delta is [%f ; %f]\n", ray->d_dist.x, ray->d_dist.y);
	printf("Ray Side is [%f ; %f]\n", ray->s_dist.x, ray->s_dist.y);
	printf("Map_Pos is [%d ; %d]\n", ray->map_x, ray->map_y);
	printf("Hit is %d\n", ray->hit);
}
