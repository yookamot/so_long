/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyota <okamotoyota@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:43:18 by yookamot          #+#    #+#             */
/*   Updated: 2025/06/17 15:14:26 by okamotoyota      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

#ifndef FRAME_DELAY
# define FRAME_DELAY 30
#endif

#ifndef GAME_OVER
# define GAME_OVER 300
#endif

static int	update_sprite_animation(t_data *data, int frame_counter)
{
	frame_counter++;
	if (frame_counter >= FRAME_DELAY)
	{
		data->current_frame++;
		if (data->current_frame >= 4)
			data->current_frame = 0;
		frame_counter = 0;
	}
	return (frame_counter);
}

static void	*draw_window_message(t_data *data)
{
	char	*message;
	char	*moves;
	char	*move_count;

	moves = ft_strdup("Moves: ");
	if (!moves)
		exit_game(data, 1);
	move_count = ft_itoa(data->player.moves);
	if (!move_count)
	{
		free(moves);
		exit_game(data, 1);
	}
	message = ft_strjoin(moves, move_count);
	free(moves);
	free(move_count);
	if (!message)
		exit_game(data, 1);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFF0000, message);
	free(message);
}

static void	game_over(t_data *data)
{
	ft_printf("\n***GAME OVER***\n");
	ft_printf("You were defeated by the enemy...\n");
	exit_game(data, 0);
}

int	game_loop(t_data *data)
{
	static int	frame_counter;

	if (data->gameover_frame == 0)
		frame_counter = update_sprite_animation(data, frame_counter);
	draw_map(data);
	draw_window_message(data);
	if (data->gameover_frame != 0)
	{
		if (data->gameover_frame == GAME_OVER)
			game_over(data);
		data->gameover_frame++;
	}
	return (0);
}
