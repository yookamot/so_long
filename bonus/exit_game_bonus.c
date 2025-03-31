/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:18:05 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/13 23:26:28 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	destroy_window(t_data *data)
{
	exit_game(data, 0);
}

static void	cleanup_textures(t_data *data)
{
	int	i;

	i = 0;
	if (data->textures.wall.img)
		mlx_destroy_image(data->mlx, data->textures.wall.img);
	if (data->textures.floor.img)
		mlx_destroy_image(data->mlx, data->textures.floor.img);
	while (i < 4)
	{
		if (data->textures.collectible[i].img)
			mlx_destroy_image(data->mlx, data->textures.collectible[i].img);
		i++;
	}
	if (data->textures.player.img)
		mlx_destroy_image(data->mlx, data->textures.player.img);
	if (data->textures.exit.img)
		mlx_destroy_image(data->mlx, data->textures.exit.img);
	if (data->textures.enemy.img)
		mlx_destroy_image(data->mlx, data->textures.enemy.img);
	if (data->textures.game_over.img)
		mlx_destroy_image(data->mlx, data->textures.game_over.img);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	cleanup_buffers(t_data *data)
{
	if (data->front_buffer.img)
		mlx_destroy_image(data->mlx, data->front_buffer.img);
	if (data->back_buffer.img)
		mlx_destroy_image(data->mlx, data->back_buffer.img);
}

void	exit_game(t_data *data, int status)
{
	if (!data)
		exit(status);
	cleanup_textures(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->map)
		free_array(data->map);
	if (data->collectibles.x)
		free(data->collectibles.x);
	if (data->collectibles.y)
		free(data->collectibles.y);
	if (data->enemy.x)
		free(data->enemy.x);
	if (data->enemy.y)
		free(data->enemy.y);
	if (data->enemy.direction)
		free(data->enemy.direction);
	cleanup_buffers(data);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
	exit(status);
}
