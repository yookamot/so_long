/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:28:31 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/20 15:44:19 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_valid_move(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] == '1')
		return (1);
	if (data->map[new_y][new_x] == 'E'
		&& data->player.collected != data->total_collectibles)
		return (1);
	return (0);
}

static void	game_clear(t_data *data)
{
	ft_printf("\n***GAME CLEAR***\n");
	ft_printf("Congratulations! You have cleared the game!\n");
	ft_printf("Total moves: %d\n", data->player.moves + 1);
	exit_game(data, 0);
}

void	new_player_set(t_data *data, int new_x, int new_y)
{
	if (data->map[data->player.y][data->player.x] == 'X')
		data->map[data->player.y][data->player.x] = 'X';
	else
		data->map[data->player.y][data->player.x] = '0';
	data->player.x = new_x;
	data->player.y = new_y;
	data->map[new_y][new_x] = 'P';
	data->player.moves++;
}

static void	move_player(t_data *data, int new_x, int new_y, int keycode)
{
	char		*message;
	static int	count;

	if (is_valid_move(data, new_x, new_y) != 0)
		return ;
	if (data->map[new_y][new_x] == 'C')
	{
		data->player.collected++;
		data->map[new_y][new_x] == '0';
	}
	if (data->map[new_y][new_x] == 'X')
	{
		new_player_set(data, new_x, new_y);
		data->gameover_frame++;
		return ;
	}
	if (data->map[new_y][new_x] == 'E'
		&& data->player.collected == data->total_collectibles)
		game_clear(data);
	new_player_set(data, new_x, new_y);
	ft_printf("Moves: %d\n", data->player.moves);
	count = add_enemy(data, count, new_x, new_y);
	draw_map(data);
	count++;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		exit_game(data, 0);
	if (check_collision(keycode, data) != 0 || data->gameover_frame != 0)
		return (data->gameover_frame++, 0);
	if (keycode == XK_w)
	{
		enemy_movement(data, data->player.x, data->player.y - 1);
		move_player(data, data->player.x, data->player.y - 1, keycode);
	}
	else if (keycode == XK_s)
	{
		enemy_movement(data, data->player.x, data->player.y + 1);
		move_player(data, data->player.x, data->player.y + 1, keycode);
	}
	else if (keycode == XK_a)
	{
		enemy_movement(data, data->player.x - 1, data->player.y);
		move_player(data, data->player.x - 1, data->player.y, keycode);
	}
	else if (keycode == XK_d)
	{
		enemy_movement(data, data->player.x + 1, data->player.y);
		move_player(data, data->player.x + 1, data->player.y, keycode);
	}
	return (0);
}
