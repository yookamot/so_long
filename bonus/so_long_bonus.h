/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:47:26 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/13 23:37:30 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define TILE_SIZE 32

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_textures
{
	t_img			wall;
	t_img			floor;
	t_img			collectible[4];
	t_img			player;
	t_img			exit;
	t_img			enemy;
	t_img			game_over;
}					t_textures;

typedef struct s_collectible
{
	int				*x;
	int				*y;
}					t_collectibles;

typedef struct s_player
{
	int				x;
	int				y;
	int				moves;
	int				collected;
}					t_player;

typedef struct s_enemy
{
	int				*x;
	int				*y;
	int				*direction;
}					t_enemy;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				win_width;
	int				win_height;
	t_textures		textures;
	t_img			front_buffer;
	t_img			back_buffer;
	int				current_buffer;
	char			**map;
	t_player		player;
	t_enemy			enemy;
	t_collectibles	collectibles;
	int				total_enemies;
	int				total_collectibles;
	int				current_frame;
	int				gameover_frame;
}					t_data;

int					check_map(t_data *data, char *map);
int					check_letter(t_data *data, char *map);
void				draw_map(t_data *data);
void				load_all_textures(t_data *data);
void				exit_game(t_data *data, int status);
int					key_hook(int keycode, t_data *data);
void				init_game(t_data *data);
void				set_dimensions(t_data *data);
int					game_loop(t_data *data);
void				read_map(t_data *data, char *file);
void				enemy_movement(t_data *data, int new_x, int new_y);
void				free_array(char **array);
int					search_p(char **cp_map);
void				search_valid_path(t_data *data);
int					search_valid_path_to_exit(char **cp_map);
int					search_valid_path_to_collectible(char **cp_map);
char				**search_surrounding_e_ex(char **cp_map, int p_x, int p_y);
char				**search_surrounding_c_ex(char **cp_map, int p_x, int p_y);
int					search_valid_path_to_enemy(char **cp_map);
char				**search_surrounding_enemy_ex(char **cp_map, int p_x,
						int p_y);
char				**copy_map(t_data *data, char **map);
void				free_map_and_exit_game(t_data *data, char **map);
void				enemy_movement_system1(t_data *data, int count);
void				enemy_movement_system2(t_data *data, int count,
						char **modified_map);
int					add_enemy(t_data *data, int count, int new_x, int new_y);
void				new_player_set(t_data *data, int new_x, int new_y);
int					check_collision(int keycode, t_data *data);
void				init_sprites(t_data *data);
int					is_valid_move(t_data *data, int new_x, int new_y);
int					destroy_window(t_data *data);

#endif