/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:06:04 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/10 17:47:29 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_xpm(t_data *data, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->width,
			&img->height);
	if (!img->img)
		exit_game(data, 1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		exit_game(data, 1);
}

void	load_all_textures(t_data *data)
{
	load_xpm(data, &data->textures.wall, "textures/wall.xpm");
	load_xpm(data, &data->textures.floor, "textures/floor.xpm");
	load_xpm(data, &data->textures.collectible, "textures/collectible.xpm");
	load_xpm(data, &data->textures.player, "textures/player.xpm");
	load_xpm(data, &data->textures.exit, "textures/exit.xpm");
}
