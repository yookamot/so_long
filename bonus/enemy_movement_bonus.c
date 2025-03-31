/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:48:52 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/10 17:36:56 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_collision(int keycode, t_data *data)
{
	int	key;

	key = 0;
	if (keycode == XK_w && data->map[data->player.y - 1][data->player.x] == 'X')
	{
		key = 1;
		new_player_set(data, data->player.x, data->player.y - 1);
	}
	if (keycode == XK_s && data->map[data->player.y + 1][data->player.x] == 'X')
	{
		key = 1;
		new_player_set(data, data->player.x, data->player.y + 1);
	}
	if (keycode == XK_a && data->map[data->player.y][data->player.x - 1] == 'X')
	{
		key = 1;
		new_player_set(data, data->player.x - 1, data->player.y);
	}
	if (keycode == XK_d && data->map[data->player.y][data->player.x + 1] == 'X')
	{
		key = 1;
		new_player_set(data, data->player.x + 1, data->player.y);
	}
	return (key);
}

static void	record_enemy_positions(t_data *data)
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
			if (data->map[y][x] == 'X')
			{
				data->enemy.x[count] = x;
				data->enemy.y[count] = y;
				data->enemy.direction[count] = 1;
				count++;
			}
			x++;
		}
		y++;
	}
}

static char	**modify_map(char **cp_map, int count, t_data *data)
{
	char	**modified_map;
	int		i;
	int		j;
	int		modify_count;

	modified_map = copy_map(data, cp_map);
	i = 0;
	modify_count = 0;
	while (modified_map[i])
	{
		j = 0;
		while (modified_map[i][j])
		{
			if (modified_map[i][j] == 'X')
			{
				modify_count++;
				if (count != modify_count)
					modified_map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (modified_map);
}

static void	update_enemy_positions(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'X')
				data->map[i][j] = '0';
			j++;
		}
		i++;
	}
	count = 0;
	while (count < data->total_enemies)
	{
		data->map[data->enemy.y[count]][data->enemy.x[count]] = 'X';
		count++;
	}
}

void	enemy_movement(t_data *data, int new_x, int new_y)
{
	int		count;
	char	**modified_map;

	if (is_valid_move(data, new_x, new_y) != 0)
		return ;
	record_enemy_positions(data);
	count = 0;
	while (count < data->total_enemies)
	{
		modified_map = modify_map(data->map, count + 1, data);
		if (search_valid_path_to_enemy(modified_map) != 0)
			enemy_movement_system1(data, count);
		else
			enemy_movement_system2(data, count, modified_map);
		free_array(modified_map);
		update_enemy_positions(data);
		count++;
	}
}
