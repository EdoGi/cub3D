/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogi <edogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:56:02 by cle-gran          #+#    #+#             */
/*   Updated: 2023/02/08 00:54:45 by edogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// TODO : Comprendre what is mlx_do_sync
int	hammam_launcher(t_map *map)
{
	set_player(map);
	mlx_loop_hook(map->mlx_ptr, dispray, map);
	mlx_hook(map->win_ptr, KeyPress, KeyPressMask, handle_press, map);
	mlx_hook(map->win_ptr, KeyRelease, KeyReleaseMask, handle_release, map);
	mlx_hook(map->win_ptr, 33, 131072, &handle_esc, map);
	// mlx_do_sync(map->mlx_ptr);
	mlx_loop(map->mlx_ptr);
	return (0);
}

int	is_cub(char *path)
{
	int	len;
	int	res;

	len = 0;
	res = 0;
	len = ft_strlen(path);
	if (len < 4)
		return (1);
	path += len - 4;
	res = ft_strncmp(path, ".cub", 4);
	return (res);
}

int	check_args(char *path)
{
	int	fd;

	if (is_cub(path))
		error_parsing(NULL, "Your argument is not a .cub");
	fd = open(path, O_DIRECTORY);
	if (fd > 0)
		error_parsing(NULL, "Your argument is a directory");
	return (0);
}

void	start_mlx(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		error_parsing(map, "The initialization of the mlx has failed");
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_W, \
	WIN_H, TITLE);
	if (map->win_ptr == NULL)
		error_parsing(map, "The initialization of the window has failed");
	map->img.img_ptr = mlx_new_image(map->mlx_ptr, WIN_W, WIN_H);
	if (map->img.img_ptr == NULL)
		error_parsing(map, "The initialization of mlx_img has failed");
	map->img.addr = mlx_get_data_addr(map->img.img_ptr, &map->img.bpp,
			&map->img.line_len, &map->img.endian);
	if (map->img.addr == NULL || map->img.img_ptr == NULL)
		error_parsing(map, "The initialization of img_address has failed");
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		check_args(av[1]);
		init_struct(&map);
		create_map(&map, av[1]);
		// display_tmap(&map);
		hammam_launcher(&map);
		hammam_finish(&map);
	}
	else
		error_parsing(NULL, "\033[1m\033[31mIncorrect usage\033[0m. Please launch the program using the following format: \033[1m'./cub3d maps/<maps chosen>.cub'\033[0m. Once the program is launched, you can move using the keys \033[1m'a', 's', 'd', 'w'\033[0m and change your view direction using the arrow keys.");
	return (0);
}
