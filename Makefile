# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okamotoyota <okamotoyota@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 17:48:57 by yookamot          #+#    #+#              #
#    Updated: 2025/06/17 15:11:35 by okamotoyota      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

MANDATORY_SRCS = mandatory/main.c \
                 mandatory/check_letter.c \
                 mandatory/check_map.c \
                 mandatory/draw_map.c \
                 mandatory/exit_game.c \
                 mandatory/init_game.c \
                 mandatory/load_textures.c \
                 mandatory/player_movement.c \
                 mandatory/read_map.c \
                 mandatory/search_valid_path.c \
                 mandatory/search_valid_path_to_collectible_ex.c \
                 mandatory/search_valid_path_to_collectible.c \
                 mandatory/search_valid_path_to_exit_ex.c \
                 mandatory/search_valid_path_to_exit.c \
                 mandatory/set_dimensions.c

BONUS_SRCS = bonus/add_enemy_bonus.c \
             bonus/main_bonus.c \
             bonus/check_letter_bonus.c \
             bonus/check_map_bonus.c \
             bonus/draw_map_bonus.c \
			 bonus/enemy_movement_bonus.c \
             bonus/enemy_movement_system1_bonus.c \
             bonus/enemy_movement_system2_bonus.c \
             bonus/exit_game_bonus.c \
             bonus/game_loop_bonus.c \
             bonus/init_game_bonus.c \
             bonus/init_sprites_bonus.c \
             bonus/load_textures_bonus.c \
             bonus/player_movement_bonus.c \
             bonus/read_map_bonus.c \
             bonus/search_valid_path_bonus.c \
             bonus/search_valid_path_to_collectible_ex_bonus.c \
             bonus/search_valid_path_to_collectible_bonus.c \
             bonus/search_valid_path_to_enemy_ex_bonus.c \
             bonus/search_valid_path_to_enemy_bonus.c \
             bonus/search_valid_path_to_exit_ex_bonus.c \
             bonus/search_valid_path_to_exit_bonus.c \
             bonus/set_dimensions_bonus.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = gcc
CFLAGS = -I./minilibx -I./libft -I./get_next_line -I./ft_printf
LDFLAGS = -L./minilibx -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

GET_NEXT_LINE_DIR = ./get_next_line
GNL_SRCS = $(GET_NEXT_LINE_DIR)/get_next_line.c $(GET_NEXT_LINE_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

MLX_DIR = ./minilibx
MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(MLX) $(MANDATORY_OBJS) $(GNL_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(MANDATORY_OBJS) $(GNL_OBJS) $(LDFLAGS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

bonus: $(MLX) $(LIBFT) $(FT_PRINTF) $(BONUS_NAME)

$(BONUS_NAME): $(MLX) $(BONUS_OBJS) $(GNL_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(BONUS_OBJS) $(GNL_OBJS) $(LDFLAGS) $(LIBFT) $(FT_PRINTF) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(MANDATORY_OBJS)
	rm -f $(BONUS_OBJS)
	rm -f $(GNL_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re