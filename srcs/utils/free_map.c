/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:52:14 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 16:48:03 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map(t_map *map)
{
	if (map->cub)
		free_tab(map->cub);
	if (map->map)
		free_tab(map->map);
	if (map->c)
		free(map->c);
	if (map->f)
		free(map->f);
}

void	free_tex_ea_we(t_map *map)
{
	t_tex	*tex;

	tex = &map->tex;
	if (tex->ea.tex_path)
	{
		free(tex->ea.tex_path);
		if (tex->no.img_ptr)
			mlx_destroy_image(map->mlx_ptr, tex->ea.img_ptr);
	}
	if (tex->we.tex_path)
	{
		free(tex->we.tex_path);
		if (tex->we.img_ptr)
			mlx_destroy_image(map->mlx_ptr, tex->we.img_ptr);
	}	
}

void	free_tex_no_so(t_map *map)
{
	t_tex	*tex;

	tex = &map->tex;
	if (tex->no.tex_path)
	{
		free(tex->no.tex_path);
		if (tex->no.img_ptr)
			mlx_destroy_image(map->mlx_ptr, tex->no.img_ptr);
	}
	if (tex->so.tex_path)
	{
		free(tex->so.tex_path);
		if (tex->so.img_ptr)
			mlx_destroy_image(map->mlx_ptr, tex->so.img_ptr);
	}
	free_tex_ea_we(map);
}

void	hammam_finish(t_map *map)
{
	if (map)
	{
		free_map(map);
		free_tex_no_so(map);
		if (map->img.img_ptr)
			mlx_destroy_image(map->mlx_ptr, map->img.img_ptr);
		if (map->win_ptr)
		{
			mlx_destroy_window(map->mlx_ptr, map->win_ptr);
			map->win_ptr = NULL;
		}
		if (map->mlx_ptr)
		{
			mlx_destroy_display(map->mlx_ptr);
			free(map->mlx_ptr);
			map->mlx_ptr = NULL;
		}
	}
	exit(0);
}
