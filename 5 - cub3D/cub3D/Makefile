# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curreg <curreg@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 20:29:16 by curreg            #+#    #+#              #
#    Updated: 2020/10/20 21:33:55 by curreg           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX_LIB = libmlx.dylib

MLX = minilibx_mms

SRCS = base/start_game.c base/set_game.c base/set_window.c \
		aux/check_int_val.c aux/check_player.c aux/check_walls.c \
		aux/fill_sprites_arr.c aux/get_sprites_count.c aux/init.c \
		aux/put_error.c aux/set_rays.c aux/sort_sprites.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c \
		hooks/hooks.c hooks/keycodes_arrows.c hooks/keycodes.c \
		parsing/check_map.c parsing/get_colors_and_tex.c \
		parsing/list_to_array.c parsing/parse_ints.c \
		parsing/parse_texture.c parsing/read_map.c print/print_3d.c \
		print/print_map.c print/print_pixel.c print/print_rays.c \
		print/print_sprite.c raycasting/raycasting_aux.c \
		raycasting/raycasting.c screenshot/take_screenshot.c \
		utils/ft_atoi.c utils/ft_calloc.c utils/ft_clear_arr.c \
		utils/ft_is_only_digit.c utils/ft_lstadd_back.c \
		utils/ft_lstclear.c utils/ft_lstnew.c utils/ft_lstsize.c \
		utils/ft_memcpy.c utils/ft_putchar_fd.c utils/ft_putstr_fd.c \
		utils/ft_split.c utils/ft_strcmp.c utils/ft_strlcpy.c \
		utils/ft_strncmp.c utils/ft_strtrim.c utils/ft_substr.c

OBJS = $(SRCS:.c=.o)			

CFLAGS = -Wall -Wextra -Werror

LIB_LINK = libmlx.dylib -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) includes/cub3d.h
	make -C $(MLX)
	mv $(MLX)/$(MLX_LIB) ./
	gcc $(LIB_LINK) $(OBJS) -o $(NAME)

%.o: %.c 
	gcc -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re