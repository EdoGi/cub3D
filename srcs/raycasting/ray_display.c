/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 04:09:44 by egiacomi          #+#    #+#             */
/*   Updated: 2022/06/19 17:05:33 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pixel_put_hex(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_wall_text(t_map *map, t_img *tex, int y, int x)
{
	int	color;
	int	r;
	int	g;
	int	b;

	r = tex->addr[(int)(map->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ 2 + (int)((y - map->ray.wall_start * 1.0) / map->ray.wall_height
			* tex->height) *tex->line_len];
	g = tex->addr[(int)(map->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ 1 + (int)((y - map->ray.wall_start * 1.0)
			/ map->ray.wall_height * tex->height) *tex->line_len];
	b = tex->addr[(int)(map->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ (int)((y - map->ray.wall_start * 1.0)
			/ map->ray.wall_height * tex->height) *tex->line_len];
	color = rgb_to_hex(r, g, b);
	if (map->ray.side == SO || map->ray.side == NO)
		color = (color >> 1) & 8355711;
	pixel_put_hex(&map->img, x, y, color);
}

void	draw_wall(t_map *map, int y, int x)
{
	if (map->ray.side == NO)
		draw_wall_text(map, &map->tex.no, y, x);
	else if (map->ray.side == SO)
		draw_wall_text(map, &map->tex.so, y, x);
	else if (map->ray.side == EA)
		draw_wall_text(map, &map->tex.ea, y, x);
	else if (map->ray.side == WE)
		draw_wall_text(map, &map->tex.we, y, x);
}

void	set_stop(t_map *map, int *start, int *end)
{
	if (map->ray.wall_start < 0)
		*start = 0;
	else
		*start = map->ray.wall_start;
	if (map->ray.wall_end >= WIN_H)
		*end = WIN_H - 1;
	else
		*end = map->ray.wall_end;
}

void	put_to_img(t_map *map, int x)
{
	t_ray	*ray;
	int		y;
	int		start;
	int		end;

	y = 0;
	ray = &map->ray;
	set_stop(map, &start, &end);
	while (y < start)
	{
		pixel_put_hex(&map->img, x, y, map->c_color);
		y++;
	}
	while (y < end)
	{
		draw_wall(map, y, x);
		y++;
	}	
	while (y < WIN_H)
	{
		pixel_put_hex(&map->img, x, y, map->f_color);
		y++;
	}
}
