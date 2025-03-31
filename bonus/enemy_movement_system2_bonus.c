/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_system2_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:12:23 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/07 16:51:54 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_movement_system2(t_data *data, int count, char **modified_map)
{
	if (modified_map[data->enemy.y[count] - 1][data->enemy.x[count]] == 'P')
	{
		data->enemy.y[count]--;
		return ;
	}
	if (modified_map[data->enemy.y[count]][data->enemy.x[count] + 1] == 'P')
	{
		data->enemy.x[count]++;
		return ;
	}
	if (modified_map[data->enemy.y[count] + 1][data->enemy.x[count]] == 'P')
	{
		data->enemy.y[count]++;
		return ;
	}
	if (modified_map[data->enemy.y[count]][data->enemy.x[count] - 1] == 'P')
	{
		data->enemy.x[count]--;
		return ;
	}
}
