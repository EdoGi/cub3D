/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:53:02 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 17:02:33 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	is_validmap(char *line)
{
	int	i;

	i = 0;
	if (!line || line[0] == 0)
		return (0);
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] \
		!= 'S' && line[i] != 'W' && line[i] != 'E' && !ft_isspace(line[i]) && \
		line[i] != '\n' && line[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

void	free_tabrgb(char **tab, int *rgb, char *str, t_map *map)
{
	if (tab)
		free_tab(tab);
	if (rgb)
		free(rgb);
	if (str)
		error_parsing(map, str);
}
