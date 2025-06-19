/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyota <okamotoyota@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:48:17 by yookamot          #+#    #+#             */
/*   Updated: 2025/06/17 15:07:46 by okamotoyota      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*map;
	t_data	*data;

	if (argc != 2)
		return (ft_printf("Error: Invalid number of arguments.\n"), 1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	read_map(data, argv[1]);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_array(data->map), free(data), 1);
	set_dimensions(data);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"so_long");
	if (!data->win)
		return (free_array(data->map), free(data->mlx), free(data), 1);
	init_game(data);
	load_all_textures(data);
	mlx_loop_hook(data->mlx, draw_map, data);
	mlx_hook(data->win, 17, 0, destroy_window, data);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
