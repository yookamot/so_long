/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_valid_path_to_exit.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:17:48 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/22 14:39:05 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_height_counter(char **cp_map)
{
	int	map_height;

	map_height = 0;
	while (cp_map[map_height])
		map_height++;
	return (map_height);
}

static char	**search_surrounding_e(char **cp_map, int p_x, int p_y)
{
	int	map_height;
	int	map_width;

	map_height = map_height_counter(cp_map);
	map_width = ft_strlen(cp_map[0]);
	if (p_y == map_height - 1 || p_y == 0 || p_x == map_width - 1 || p_x == 0)
		return (search_surrounding_e_ex(cp_map, p_x, p_y));
	if (cp_map[p_y - 1][p_x] == 'E' || cp_map[p_y][p_x + 1] == 'E' || cp_map[p_y
		+ 1][p_x] == 'E' || cp_map[p_y][p_x - 1] == 'E')
		return (NULL);
	if (cp_map[p_y - 1][p_x] == '0' || cp_map[p_y - 1][p_x] == 'C')
		cp_map[p_y - 1][p_x] = 'P';
	if (cp_map[p_y][p_x + 1] == '0' || cp_map[p_y][p_x + 1] == 'C')
		cp_map[p_y][p_x + 1] = 'P';
	if (cp_map[p_y + 1][p_x] == '0' || cp_map[p_y + 1][p_x] == 'C')
		cp_map[p_y + 1][p_x] = 'P';
	if (cp_map[p_y][p_x - 1] == '0' || cp_map[p_y][p_x - 1] == 'C')
		cp_map[p_y][p_x - 1] = 'P';
	cp_map[p_y][p_x] = '1';
	return (cp_map);
}

int	search_valid_path_to_exit(char **cp_map)
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
					cp_map = search_surrounding_e(cp_map, j, i);
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
