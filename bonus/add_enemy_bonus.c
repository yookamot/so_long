/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_enemy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:19:03 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/22 14:26:44 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	*copy_enemy_information(int *info, int count)
{
	int	*copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * (count + 1));
	if (!copy)
		return (free(info), NULL);
	i = 0;
	while (i < count)
	{
		copy[i] = info[i];
		i++;
	}
	copy[i] = 0;
	free(info);
	return (copy);
}

static void	update_map(t_data *data, int new_x, int new_y)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0' && new_x != j && new_y != i)
			{
				data->map[i][j] == 'X';
				data->enemy.y[data->total_enemies - 1] = i;
				data->enemy.x[data->total_enemies - 1] = j;
				data->enemy.direction[data->total_enemies - 1] = 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	add_enemy(t_data *data, int count, int new_x, int new_y)
{
	if (count != 39)
		return (count);
	data->enemy.x = copy_enemy_information(data->enemy.x, data->total_enemies);
	data->enemy.y = copy_enemy_information(data->enemy.y, data->total_enemies);
	data->enemy.direction = copy_enemy_information(data->enemy.direction,
			data->total_enemies);
	if (!data->enemy.x || !data->enemy.y || !data->enemy.direction)
		exit_game(data, 1);
	data->total_enemies++;
	update_map(data, new_x, new_y);
	ft_printf("A new enemy has appeared! Total enemies: %d\n",
		data->total_enemies);
	return (0);
}
