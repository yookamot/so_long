/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_system1_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:53:05 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/04 19:36:18 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	enemy_movement_up(t_data *data, int count, int move)
{
	if (move == 1)
		return (1);
	if (data->map[data->enemy.y[count] - 1][data->enemy.x[count]] == '0')
	{
		data->enemy.y[count]--;
		return (1);
	}
	else
	{
		data->enemy.direction[count] = 2;
		return (0);
	}
}

static int	enemy_movement_right(t_data *data, int count, int move)
{
	if (move == 1)
		return (1);
	if (data->map[data->enemy.y[count]][data->enemy.x[count] + 1] == '0')
	{
		data->enemy.x[count]++;
		return (1);
	}
	else
	{
		data->enemy.direction[count] = 3;
		return (0);
	}
}

static int	enemy_movement_down(t_data *data, int count, int move)
{
	if (move == 1)
		return (1);
	if (data->map[data->enemy.y[count] + 1][data->enemy.x[count]] == '0')
	{
		data->enemy.y[count]++;
		return (1);
	}
	else
	{
		data->enemy.direction[count] = 4;
		return (0);
	}
}

static int	enemy_movement_left(t_data *data, int count, int move)
{
	if (move == 1)
		return (1);
	if (data->map[data->enemy.y[count]][data->enemy.x[count] - 1] == '0')
	{
		data->enemy.x[count]--;
		return (1);
	}
	else
	{
		data->enemy.direction[count] = 1;
		return (0);
	}
}

void	enemy_movement_system1(t_data *data, int count)
{
	int	move;

	if (data->map[data->enemy.y[count] - 1][data->enemy.x[count]] != '0'
		&& data->map[data->enemy.y[count] + 1][data->enemy.x[count]] != '0'
		&& data->map[data->enemy.y[count]][data->enemy.x[count] + 1] != '0'
		&& data->map[data->enemy.y[count]][data->enemy.x[count] - 1] != '0')
		return ;
	move = 0;
	while (move == 0)
	{
		if (data->enemy.direction[count] == 1)
			move = enemy_movement_up(data, count, move);
		if (data->enemy.direction[count] == 2)
			move = enemy_movement_right(data, count, move);
		if (data->enemy.direction[count] == 3)
			move = enemy_movement_down(data, count, move);
		if (data->enemy.direction[count] == 4)
			move = enemy_movement_left(data, count, move);
	}
	return ;
}
