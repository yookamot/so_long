/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:28:31 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/22 14:29:40 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_move(t_data *data, int new_x, int new_y)
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

static void	move_player(t_data *data, int new_x, int new_y)
{
	char	*message;

	if (is_valid_move(data, new_x, new_y) != 0)
		return ;
	if (data->map[new_y][new_x] == 'C')
	{
		data->player.collected++;
		data->map[new_y][new_x] == '0';
	}
	if (data->map[new_y][new_x] == 'E'
		&& data->player.collected == data->total_collectibles)
		game_clear(data);
	data->map[data->player.y][data->player.x] = '0';
	data->player.x = new_x;
	data->player.y = new_y;
	data->map[new_y][new_x] = 'P';
	data->player.moves++;
	ft_printf("Moves: %d\n", data->player.moves);
	draw_map(data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		exit_game(data, 0);
	else if (keycode == XK_w)
		move_player(data, data->player.x, data->player.y - 1);
	else if (keycode == XK_s)
		move_player(data, data->player.x, data->player.y + 1);
	else if (keycode == XK_a)
		move_player(data, data->player.x - 1, data->player.y);
	else if (keycode == XK_d)
		move_player(data, data->player.x + 1, data->player.y);
	return (0);
}
