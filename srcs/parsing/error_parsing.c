/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:30:04 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/16 23:00:33 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	error_parsing(t_map *map, char *str)
{
	printf("Error\n%s\n", str);
	if (map)
		hammam_finish(map);
	exit (0);
}
