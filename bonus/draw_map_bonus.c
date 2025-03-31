/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:40:31 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/10 17:45:26 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_img	*get_draw_buffer(t_data *data)
{
	if (data->current_buffer == 0)
		return (&data->back_buffer);
	else
		return (&data->front_buffer);
}

static void	draw_texture(t_data *data, t_img *texture, int x, int y)
{
	t_img	*buffer;
	int		i;
	int		j;
	int		*src;
	int		*dst;

	buffer = get_draw_buffer(data);
	src = (int *)texture->addr;
	dst = (int *)buffer->addr;
	y *= TILE_SIZE;
	x *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (src[i * TILE_SIZE + j] != 0)
				dst[(y + i) * (data->win_width) + (x + j)] = src[i * TILE_SIZE
					+ j];
			j++;
		}
		i++;
	}
}

static void	draw_all_textures(t_data *data, int x, int y)
{
	draw_texture(data, &data->textures.floor, x, y);
	if (data->map[y][x] == '1')
		draw_texture(data, &data->textures.wall, x, y);
	else if (data->map[y][x] == 'C')
		draw_texture(data, &data->textures.collectible[data->current_frame], x,
			y);
	else if (data->map[y][x] == 'P')
	{
		if (data->gameover_frame != 0)
			draw_texture(data, &data->textures.game_over, x, y);
		else
			draw_texture(data, &data->textures.player, x, y);
	}
	else if (data->map[y][x] == 'E')
		draw_texture(data, &data->textures.exit, x, y);
	else if (data->map[y][x] == 'X')
		draw_texture(data, &data->textures.enemy, x, y);
}

static void	swap_buffers(t_data *data)
{
	t_img	*display_buffer;

	display_buffer = get_draw_buffer(data);
	mlx_put_image_to_window(data->mlx, data->win, display_buffer->img, 0, 0);
	if (data->current_buffer == 0)
		data->current_buffer = 1;
	else
		data->current_buffer = 0;
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			draw_all_textures(data, x, y);
			x++;
		}
		y++;
	}
	swap_buffers(data);
}
