/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:49:07 by cle-gran          #+#    #+#             */
/*   Updated: 2022/06/19 17:32:13 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../mlx/mlx.h"
# include <X11/Xlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include <math.h>
# include <string.h>

# include "../libft/srcs/libft.h"

# define BUFFER_SIZE	1
# define TITLE			"HAMMAM 3D"
# define ESC			65307
# define GOWE			97
# define GONO			119
# define GOEA			100
# define GOSO			115
# define LOOKNO			65362
# define LOOKEA			65363
# define LOOKSO			65364
# define LOOKWE			65361

# define WIN_H			768
# define WIN_W			1240

# define MINIMAP_SIZE 4
# define MINIMAP_OFFSET 20

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define FALSE	0
# define TRUE	1

typedef struct s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct s_ray
{
	int		go_ray;
	t_coord	dir;
	t_coord	d_dist;
	t_coord	s_dist;
	double	w_dist;
	t_coord	step;
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	double	cam_x;
	int		wall_height;
	int		wall_start;
	int		wall_end;
	double	wall_x;
}				t_ray;

typedef struct s_play
{
	t_coord	pos;
	t_coord	dir;
	t_coord	plane;
	int		look;
	int		card;
	double	mv_spd;
	double	rt_spd;
}				t_play;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
	char	*tex_path;
}				t_img;
/* 
FIXME : To put?
	True or False if already implemented ; No Leaks then :) 
	Total args ? 
*/
typedef struct s_key {
	int		left;
	int		right;
	int		up;
	int		down;
	int		rot_l;
	int		rot_r;
	int		rot_u;
	int		rot_d;
	int		exit;
}				t_key;

typedef struct s_tex {
	t_img	ea;
	t_img	we;
	t_img	no;
	t_img	so;
}				t_tex;

// TODO : Del text card &  del f and c
typedef struct s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		wc;
	int		hc;
	char	**cub;
	char	*f;
	int		f_color;
	char	*c;
	int		c_color;
	int		wm;
	int		hm;
	char	**map;
	t_play	player;
	t_ray	ray;
	t_img	img;
	t_tex	tex;
	t_key	key;
}				t_map;

/*PARSING*/
void	init_struct(t_map *map);
void	get_size_cub(t_map *map, char *path);
void	build_cub(t_map *map, char *path);
void	fill_cub(t_map *map, char *path);
void	check_cub(t_map *map, char **cub);
void	create_map(t_map *map, char *path);
void	fill_map(t_map *map, char *path);
void	check_closedmap(t_map *map, char **tab);
int		is_perso(char c);
void	check_oneperso(t_map *map, char **tab);
void	error_parsing(t_map *map, char *str);
char	*get_restext(t_map *map, char **cub, char *text, int *state);
int		is_validmap(char *line);
char	*get_text(t_map *map, char **cub, char *text);
int		get_next_line(int fd, char **line);
void	fill_tex(t_map *map);
void	init_tex(t_map *map, t_img *tex_img);
void	free_tabrgb(char **tab, int *rgb, char *str, t_map *map);
char	*gnl_strdup(char *source);
int		is_not_newline(char *s);
int		gnl_strlen(char *str);

/*MOVES*/
int		handle_press(int key, t_map *map);
int		handle_release(int key, t_map *map);
int		handle_esc(t_map *map);
int		key_loop(t_map *map);
void	ft_move_w(t_map *map);
void	ft_move_s(t_map *map, t_play *player);
void	ft_move_d(t_map *map, t_play *player);
void	ft_move_a(t_map *map, t_play *player);
void	ft_rot_left(t_map *map);
void	ft_rot_right(t_map *map);
void	ft_rot_up(t_map *map);
void	ft_rot_down(t_map *map);

/*UTILS*/
int		ft_isspace(int c);
void	ft_close(int fd);
char	*ft_gnljoin(char *s1, char *s2);
char	*ft_freedup(char *str, char *str2);
char	*ft_strduplen(char *s, int len);
void	free_tab(char **tab);
void	hammam_finish(t_map *map);
int		rgb_to_hex(int r, int g, int b);
void	free_tex_no_so(t_map *map);
void	free_tex_ea_we(t_map *map);

/*RAYCASTING*/
int		dispray(t_map *map);
void	set_player(t_map *map);
void	put_to_img(t_map *map, int x);
void	find_walldist(t_map *map, t_ray *ray);
void	wall_height(t_map *map, t_ray *ray);
void	print_ray(t_ray *ray);
void	print_player(t_play *player);
void	pixel_put_hex(t_img *img, int x, int y, int color);

/*MINIMAP*/
int		create_minimap(t_map *map);

/*DISPLAY*/
void	start_mlx(t_map *map);
void	display_tmap(t_map *map);
void	display_tab(char **tab);
void	display_tabint(int	*tab);

#endif
