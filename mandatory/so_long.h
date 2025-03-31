/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:43:02 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/13 23:38:16 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	t_img			collectible;
	t_img			player;
	t_img			exit;
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
	t_collectibles	collectibles;
	int				total_collectibles;
}					t_data;

int					check_map(t_data *data, char *map);
int					check_letter(t_data *data, char *map);
int					draw_map(t_data *data);
void				load_all_textures(t_data *data);
void				read_map(t_data *data, char *file);
void				exit_game(t_data *data, int status);
int					key_hook(int keycode, t_data *data);
void				init_game(t_data *data);
void				set_dimensions(t_data *data);
int					search_p(char **cp_map);
void				search_valid_path(t_data *data);
int					search_valid_path_to_exit(char **cp_map);
char				**search_surrounding_e_ex(char **cp_map, int p_x, int p_y);
int					search_valid_path_to_collectible(char **cp_map);
char				**search_surrounding_c_ex(char **cp_map, int p_x, int p_y);
void				free_array(char **array);
int					destroy_window(t_data *data);

#endif