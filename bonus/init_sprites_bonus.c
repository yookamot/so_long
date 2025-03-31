/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:18:46 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/10 15:50:46 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_sprites(t_data *data)
{
	data->textures.collectible[0].img = NULL;
	data->textures.collectible[1].img = NULL;
	data->textures.collectible[2].img = NULL;
	data->textures.collectible[3].img = NULL;
	data->current_frame = 0;
}
