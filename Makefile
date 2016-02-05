# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2015/12/19 20:45:39 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

INCLUDES_MLX = ./minilibx_macos/includes

LIBFT_PATH = ./libft

LIBMLX_PATH = ./minilibx_macos

SRC_NAME =	ft_can_be_atoi.c ft_coord.c ft_fill_int_tab2.c ft_hook.c \
		  	ft_int_tab2_new.c ft_lstcount_node.c ft_lstread_file.c \
		  	ft_lstseek_max_x.c ft_lstsplit_whitespaces_content.c \
		  	ft_max.c ft_mlx_i_draw_diag_line1234.c \
			ft_mlx_i_draw_diag_line5678.c ft_mlx_i_draw_hori_line.c \
			ft_mlx_i_draw_verti_line.c ft_mlx_i_draw_wireframe.c \
			ft_mlx_i_drawline.c \
			ft_mlx_i_pixel_put.c ft_mlx_i_position_in_2d.c \
			ft_scale_dec.c ft_scale_init.c \
			ft_scale_seek_min_max.c ft_scale_value.c \
			ft_scale_z_based_color.c ft_strsplit_allspace.c main.c \

SRC_PATH = ./srcs/

SRC =	$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =	$(SRC_NAME:.c=.o)

NAME = fdf

all :	libft libmlx $(NAME)

libft :
	make -C $(LIBFT_PATH)

libmlx :
	make -C $(LIBMLX_PATH)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lft -lmlx -I$(INCLUDES) -I$(INCLUDES_LIBFT) -I$(INCLUDES_MLX) -L$(LIBFT_PATH) -L$(LIBMLX_PATH) -framework OpenGL -framework Appkit

$(OBJ) :
	$(CC) -c $(SRC) $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT) -I$(INCLUDES_MLX)

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(LIBMLX_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean
	rm -rf $(LIBMLX_PATH)/libmlx.a

re : fclean all

.PHONY : all clean fclean re libft libmlx
