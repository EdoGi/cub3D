# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 20:10:08 by root              #+#    #+#              #
#    Updated: 2022/05/01 19:35:18 by cle-gran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm

INCLUDES = srcs/libft.h

SRCS = ft_memset.c \
	   ft_bzero.c \
	   ft_memccpy.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strncmp.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_atoi.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_calloc.c \
	   ft_memchr.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_lstdelone.c \

OBJS_DIR = objs/

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

$(OBJS_DIR)%.o: srcs/%.c
	mkdir -p $(OBJS_DIR)
	${CC} -c ${CFLAGS} -o $@ $< -I ${INCLUDES}

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

clean:
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
