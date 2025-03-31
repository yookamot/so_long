/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_valid_path_to_exit_ex_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:57:10 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/04 15:52:36 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**search_surrounding_e_ex1(char **cp_map, int p_x, int p_y)
{
	if (cp_map[p_y - 1][p_x] == 'E' || cp_map[p_y][p_x + 1] == 'E'
		|| cp_map[p_y][p_x - 1] == 'E')
		return (NULL);
	if (cp_map[p_y - 1][p_x] == '0' || cp_map[p_y - 1][p_x] == 'C' || cp_map[p_y
		- 1][p_x] == 'X')
		cp_map[p_y - 1][p_x] = 'P';
	if (cp_map[p_y][p_x + 1] == '0' || cp_map[p_y][p_x + 1] == 'C'
		|| cp_map[p_y][p_x + 1] == 'X')
		cp_map[p_y][p_x + 1] = 'P';
	if (cp_map[p_y][p_x - 1] == '0' || cp_map[p_y][p_x - 1] == 'C'
		|| cp_map[p_y][p_x - 1] == 'P')
		cp_map[p_y][p_x - 1] = 'P';
	cp_map[p_y][p_x] = '1';
	return (cp_map);
}

static char	**search_surrounding_e_ex2(char **cp_map, int p_x, int p_y)
{
	if (cp_map[p_y + 1][p_x] == 'E' || cp_map[p_y][p_x + 1] == 'E'
		|| cp_map[p_y][p_x - 1] == 'E')
		return (NULL);
	if (cp_map[p_y + 1][p_x] == '0' || cp_map[p_y + 1][p_x] == 'C' || cp_map[p_y
		+ 1][p_x] == 'X')
		cp_map[p_y + 1][p_x] = 'P';
	if (cp_map[p_y][p_x + 1] == '0' || cp_map[p_y][p_x + 1] == 'C'
		|| cp_map[p_y][p_x + 1] == 'X')
		cp_map[p_y][p_x + 1] = 'P';
	if (cp_map[p_y][p_x - 1] == '0' || cp_map[p_y][p_x - 1] == 'C'
		|| cp_map[p_y][p_x - 1] == 'P')
		cp_map[p_y][p_x - 1] = 'P';
	cp_map[p_y][p_x] = '1';
	return (cp_map);
}

static char	**search_surrounding_e_ex3(char **cp_map, int p_x, int p_y)
{
	if (cp_map[p_y - 1][p_x] == 'E' || cp_map[p_y + 1][p_x] == 'E'
		|| cp_map[p_y][p_x - 1] == 'E')
		return (NULL);
	if (cp_map[p_y - 1][p_x] == '0' || cp_map[p_y - 1][p_x] == 'C' || cp_map[p_y
		- 1][p_x] == 'X')
		cp_map[p_y - 1][p_x] = 'P';
	if (cp_map[p_y + 1][p_x] == '0' || cp_map[p_y + 1][p_x] == 'C' || cp_map[p_y
		+ 1][p_x] == 'X')
		cp_map[p_y + 1][p_x] = 'P';
	if (cp_map[p_y][p_x - 1] == '0' || cp_map[p_y][p_x - 1] == 'C'
		|| cp_map[p_y][p_x - 1] == 'P')
		cp_map[p_y][p_x - 1] = 'P';
	cp_map[p_y][p_x] = '1';
	return (cp_map);
}

static char	**search_surrounding_e_ex4(char **cp_map, int p_x, int p_y)
{
	if (cp_map[p_y - 1][p_x] == 'E' || cp_map[p_y][p_x + 1] == 'E' || cp_map[p_y
		+ 1][p_x] == 'E')
		return (NULL);
	if (cp_map[p_y - 1][p_x] == '0' || cp_map[p_y - 1][p_x] == 'C' || cp_map[p_y
		- 1][p_x] == 'X')
		cp_map[p_y - 1][p_x] = 'P';
	if (cp_map[p_y][p_x + 1] == '0' || cp_map[p_y][p_x + 1] == 'C'
		|| cp_map[p_y][p_x + 1] == 'X')
		cp_map[p_y][p_x + 1] = 'P';
	if (cp_map[p_y + 1][p_x] == '0' || cp_map[p_y + 1][p_x] == 'C' || cp_map[p_y
		+ 1][p_x] == 'X')
		cp_map[p_y + 1][p_x] = 'P';
	cp_map[p_y][p_x] = '1';
	return (cp_map);
}

char	**search_surrounding_e_ex(char **cp_map, int p_x, int p_y)
{
	int	map_height;
	int	map_width;

	map_height = 0;
	while (cp_map[map_height])
		map_height++;
	map_width = ft_strlen(cp_map[0]);
	if (p_y == map_height - 1)
		return (search_surrounding_e_ex1(cp_map, p_x, p_y));
	if (p_y == 0)
		return (search_surrounding_e_ex2(cp_map, p_x, p_y));
	if (p_x == map_width - 1)
		return (search_surrounding_e_ex3(cp_map, p_x, p_y));
	if (p_x == 0)
		return (search_surrounding_e_ex4(cp_map, p_x, p_y));
}
