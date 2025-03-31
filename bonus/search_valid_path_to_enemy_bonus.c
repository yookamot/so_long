/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_valid_path_to_enemy_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:58:41 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/04 19:54:54 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**search_surrounding_enemy(char **cp_map, int p_x, int p_y)
{
	int	map_height;
	int	map_width;

	map_height = 0;
	while (cp_map[map_height])
		map_height++;
	map_width = ft_strlen(cp_map[0]);
	if (p_y == map_height - 1 || p_y == 0 || p_x == map_width - 1 || p_x == 0)
		return (search_surrounding_enemy_ex(cp_map, p_x, p_y));
	if (cp_map[p_y - 1][p_x] == 'X' || cp_map[p_y][p_x + 1] == 'X' || cp_map[p_y
		+ 1][p_x] == 'X' || cp_map[p_y][p_x - 1] == 'X')
		return (NULL);
	if (cp_map[p_y - 1][p_x] == '0')
		cp_map[p_y - 1][p_x] = 'P';
	if (cp_map[p_y][p_x + 1] == '0')
		cp_map[p_y][p_x + 1] = 'P';
	if (cp_map[p_y + 1][p_x] == '0')
		cp_map[p_y + 1][p_x] = 'P';
	if (cp_map[p_y][p_x - 1] == '0')
		cp_map[p_y][p_x - 1] = 'P';
	cp_map[p_y][p_x] = 'Y';
	return (cp_map);
}

int	search_valid_path_to_enemy(char **cp_map)
{
	int	i;
	int	j;

	while (search_p(cp_map) == 0)
	{
		i = 0;
		while (cp_map[i])
		{
			j = 0;
			while (cp_map[i][j])
			{
				if (cp_map[i][j] == 'P')
				{
					cp_map = search_surrounding_enemy(cp_map, j, i);
					if (!cp_map)
						return (0);
				}
				j++;
			}
			i++;
		}
	}
	return (1);
}
