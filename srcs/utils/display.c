/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 22:02:28 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 02:29:00 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	display_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	display_tabint(int	*tab)
{
	int	i;

	i = 0;
	if (!tab)
	{
		printf("\n");
		return ;
	}
	printf("%d|%d|%d\n", tab[0], tab[1], tab[2]);
}

void	display_tmap(t_map *map)
{
	printf("wc : %d\n", map->wc);
	printf("hc : %d\n", map->hc);
	printf("no : %s of %d x %d\n", map->tex.no.tex_path,
		map->tex.no.width, map->tex.no.height);
	printf("so : %s of %d x %d\n", map->tex.so.tex_path,
		map->tex.so.width, map->tex.so.height);
	printf("ea : %s of %d x %d\n", map->tex.ea.tex_path,
		map->tex.ea.width, map->tex.ea.height);
	printf("we : %s of %d x %d\n", map->tex.we.tex_path,
		map->tex.we.width, map->tex.we.height);
	printf("f : %s\n", map->f);
	printf("f_color : %d\n", map->f_color);
	printf("c : %s\n", map->c);
	printf("c_color : %d\n", map->c_color);
	printf("wm : %d\n", map->wm);
	printf("hm : %d\n", map->hm);
	display_tab(map->map);
}
