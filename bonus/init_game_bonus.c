/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:11:27 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/10 17:45:52 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	find_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	find_collectibles(t_data *data)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
			{
				data->collectibles.x[count] = x;
				data->collectibles.y[count] = y;
				count++;
			}
			x++;
		}
		y++;
	}
}

static void	find_enemies(t_data *data)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'X')
			{
				data->enemy.x[count] = x;
				data->enemy.y[count] = y;
				count++;
			}
			x++;
		}
		y++;
	}
}

static void	init_buffers(t_data *data)
{
	data->front_buffer.img = mlx_new_image(data->mlx, data->win_width,
			data->win_height);
	data->front_buffer.addr = mlx_get_data_addr(data->front_buffer.img,
			&data->front_buffer.bits_per_pixel, &data->front_buffer.line_length,
			&data->front_buffer.endian);
	data->back_buffer.img = mlx_new_image(data->mlx, data->win_width,
			data->win_height);
	data->back_buffer.addr = mlx_get_data_addr(data->back_buffer.img,
			&data->back_buffer.bits_per_pixel, &data->back_buffer.line_length,
			&data->back_buffer.endian);
	data->current_buffer = 0;
}

void	init_game(t_data *data)
{
	data->player.moves = 0;
	data->player.collected = 0;
	data->textures.wall.img = NULL;
	data->textures.floor.img = NULL;
	data->textures.exit.img = NULL;
	data->textures.enemy.img = NULL;
	data->textures.player.img = NULL;
	data->textures.game_over.img = NULL;
	init_sprites(data);
	find_player(data);
	data->collectibles.x = (int *)malloc(sizeof(int)
			* (data->total_collectibles));
	data->collectibles.y = (int *)malloc(sizeof(int)
			* (data->total_collectibles));
	data->enemy.x = (int *)malloc(sizeof(int) * (data->total_enemies));
	data->enemy.y = (int *)malloc(sizeof(int) * (data->total_enemies));
	data->enemy.direction = (int *)malloc(sizeof(int) * (data->total_enemies));
	if (!data->collectibles.x || !data->collectibles.y || !data->enemy.x
		|| !data->enemy.y || !data->enemy.direction)
		exit_game(data, 1);
	data->gameover_frame = 0;
	find_collectibles(data);
	find_enemies(data);
	init_buffers(data);
}
