/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:03:00 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 17:03:12 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_big_pixel(t_img *mini, int x, int y, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SIZE)
	{
		j = 0;
		while (j < MINIMAP_SIZE)
		{
			pixel_put_hex(mini, (x + i), (y + j), col);
			j++;
		}
		i++;
	}
}

int	create_minimap(t_map *map)
{
	int	i;
	int	j;
	int	y;
	int	x;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			x = j * MINIMAP_SIZE + MINIMAP_OFFSET;
			y = i * MINIMAP_SIZE + MINIMAP_OFFSET;
			if (i == (int)map->player.pos.x && j == (int)map->player.pos.y)
				put_big_pixel(&map->img, x, y, 0xFF0000);
			else if (map->map[i][j] == '1')
				put_big_pixel(&map->img, x, y, -map->c_color);
			else if (map->map[i][j] == '0')
				put_big_pixel(&map->img, x, y, 0xFFFFFF);
			j++;
		}
		i++;
	}
	return (0);
}
