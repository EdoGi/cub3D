/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:35:50 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 02:45:37 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	handle_press(int key, t_map *map)
{
	if (key == ESC)
		map->key.exit = TRUE;
	else if (key == GONO)
		map->key.up = TRUE;
	else if (key == GOSO)
		map->key.down = TRUE;
	else if (key == GOEA)
		map->key.right = TRUE;
	else if (key == GOWE)
		map->key.left = TRUE;
	else if (key == LOOKWE)
		map->key.rot_l = TRUE;
	else if (key == LOOKEA)
		map->key.rot_r = TRUE;
	else if (key == LOOKNO)
		map->key.rot_u = TRUE;
	else if (key == LOOKSO)
		map->key.rot_d = TRUE;
	return (0);
}

int	handle_release(int key, t_map *map)
{
	if (key == ESC)
		map->key.exit = FALSE;
	else if (key == GONO)
		map->key.up = FALSE;
	else if (key == GOSO)
		map->key.down = FALSE;
	else if (key == GOEA)
		map->key.right = FALSE;
	else if (key == GOWE)
		map->key.left = FALSE;
	else if (key == LOOKWE)
		map->key.rot_l = FALSE;
	else if (key == LOOKEA)
		map->key.rot_r = FALSE;
	else if (key == LOOKNO)
		map->key.rot_u = FALSE;
	else if (key == LOOKSO)
		map->key.rot_d = FALSE;
	return (0);
}

int	handle_esc(t_map *map)
{
	hammam_finish(map);
	exit(0);
	return (0);
}
