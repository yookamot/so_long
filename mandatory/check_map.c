/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:08:14 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/18 17:07:08 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ERR_REC "Error: The map is not rectangular.\n"
#define ERR_WALL "Error: The map must be surrounded by walls.\n"

static int	check_horizonal_wall(char *map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if (map[i] != '1')
			return (1);
		i++;
	}
	j = ft_strlen(map) - 1;
	while (j >= 0 && map[j] != '\n')
		j--;
	j++;
	while (map[j] && map[j] != '\n')
	{
		if (map[j] != '1')
			return (1);
		j++;
	}
	return (0);
}

static int	check_vertical_wall(char *map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (map[i] == '\n')
		{
			if (map[i - 1] != '1' || map[i + 1] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}

static int	check_rectangular(char *map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[count] != '\n' && map[count] != '\0')
		count++;
	while (map[i])
	{
		j = 0;
		while (map[i] != '\n' && map[i] != '\0')
		{
			i++;
			j++;
		}
		if (j != count)
			return (ft_printf(ERR_REC), 1);
		if (map[i] == '\n')
			i++;
	}
	return (0);
}

int	check_map(t_data *data, char *map)
{
	int	letter;
	int	h_wall;
	int	v_wall;
	int	rec;

	letter = check_letter(data, map);
	h_wall = check_horizonal_wall(map);
	v_wall = check_vertical_wall(map);
	rec = check_rectangular(map);
	if (h_wall != 0 || v_wall != 0)
		ft_printf(ERR_WALL);
	if (letter != 0 || h_wall != 0 || v_wall != 0 || rec != 0)
		return (1);
	return (0);
}
