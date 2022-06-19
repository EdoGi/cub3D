/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:51:54 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 17:02:26 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	get_color(t_map *map, char *str)
{
	char	**tab;
	int		color;
	int		i;
	int		*rgb;

	tab = ft_split(str, ',');
	if (size_tab(tab) != 3)
		free_tabrgb(tab, NULL, "One rgb is unvalid", map);
	rgb = ft_calloc(sizeof(int), 3);
	i = 0;
	while (i < 3)
	{
		rgb[i] = ft_atoi(tab[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			free_tabrgb(tab, rgb, "One rgb is unvalid", map);
		i++;
	}
	color = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
	free_tabrgb(tab, rgb, NULL, map);
	return (color);
}

void	init_tex(t_map *map, t_img *tex_img)
{
	tex_img->img_ptr = mlx_xpm_file_to_image(map->mlx_ptr, tex_img->tex_path,
			&tex_img->width, &tex_img->height);
	if (!tex_img->img_ptr)
		error_parsing(map, "Creation of texture image has failed");
	tex_img->addr = mlx_get_data_addr(tex_img->img_ptr, &tex_img->bpp,
			&tex_img->line_len, &tex_img->endian);
	if (tex_img->addr == NULL || tex_img->addr == NULL)
		error_parsing(map, "The initialization of texture_dress has failed\n");
}

void	fill_tmap(t_map *map)
{
	check_cub(map, map->cub);
	map->tex.no.tex_path = get_text(map, map->cub, "NO ");
	map->tex.so.tex_path = get_text(map, map->cub, "SO ");
	map->tex.ea.tex_path = get_text(map, map->cub, "EA ");
	map->tex.we.tex_path = get_text(map, map->cub, "WE ");
	map->f = get_text(map, map->cub, "F ");
	map->f_color = get_color(map, map->f);
	map->c = get_text(map, map->cub, "C ");
	map->c_color = get_color(map, map->c);
}

void	create_map(t_map *map, char *path)
{
	get_size_cub(map, path);
	fill_cub(map, path);
	fill_tmap(map);
	fill_map(map, path);
	start_mlx(map);
	fill_tex(map);
}
