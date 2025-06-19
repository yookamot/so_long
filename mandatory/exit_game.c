/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyota <okamotoyota@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:18:05 by yookamot          #+#    #+#             */
/*   Updated: 2025/06/17 15:08:19 by okamotoyota      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_data *data)
{
	exit_game(data, 0);
	return (0);
}

static void	cleanup_textures(t_data *data)
{
	if (data->textures.wall.img)
		mlx_destroy_image(data->mlx, data->textures.wall.img);
	if (data->textures.floor.img)
		mlx_destroy_image(data->mlx, data->textures.floor.img);
	if (data->textures.collectible.img)
		mlx_destroy_image(data->mlx, data->textures.collectible.img);
	if (data->textures.player.img)
		mlx_destroy_image(data->mlx, data->textures.player.img);
	if (data->textures.exit.img)
		mlx_destroy_image(data->mlx, data->textures.exit.img);
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
	cleanup_buffers(data);
	if (data->mlx)
	{
		free(data->mlx);
	}
	free(data);
	exit(status);
}
