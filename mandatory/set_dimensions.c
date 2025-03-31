/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:18:17 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/10 17:47:49 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_dimensions(t_data *data)
{
	int	map_height;
	int	map_width;

	map_height = 0;
	while (data->map[map_height])
		map_height++;
	map_width = ft_strlen(data->map[0]);
	data->win_height = map_height * TILE_SIZE;
	data->win_width = map_width * TILE_SIZE;
}
