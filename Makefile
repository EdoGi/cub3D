NAME = cub3d

SRCS = 	srcs/main.c						\
		srcs/utils/display.c			\
		srcs/utils/free_map.c			\
		srcs/utils/utils.c				\
		srcs/parsing/gnl.c				\
		srcs/parsing/gnl_utils.c		\
		srcs/parsing/init_struct.c		\
		srcs/parsing/init_cub.c			\
		srcs/parsing/init_map.c			\
		srcs/parsing/init_tmap.c		\
		srcs/parsing/check_walls.c		\
		srcs/parsing/check_perso.c		\
		srcs/parsing/error_parsing.c	\
		srcs/parsing/find_textures.c	\
		srcs/parsing/utils_map.c		\
		srcs/moves/handle.c				\
		srcs/moves/keys.c				\
		srcs/moves/rot.c				\
		srcs/raycasting/init_ray.c		\
		srcs/raycasting/set_player.c	\
		srcs/raycasting/ray_display.c	\
		srcs/raycasting/ray_utils.c		\
		srcs/raycasting/wall_size.c		\
		srcs/minimap/create_minimap.c	\


BONUS = srcs/main.c 

OBJS = ${SRCS:.c=.o}

LIBFT_PATH	= ./libft

LIBFT		= libft/libft.a

INCLUDE_DIR = -I ./includes

INC = ./includes/cub.h

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11

all : ${NAME}

$(NAME) : $(OBJS) $(LIBFT) $(INC)
	make -s -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE_DIR) -o $(NAME) $(FL_MLX) $(LIBFT)
	@echo "$(NAME) created"

$(LIBFT):
			make -s -C $(LIBFT_PATH)

%.o:%.c
	${CC} ${CFLAGS} -Imlx -Ibass -I includes -o $@ -c $<

clean :
	${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY : clean fclean re