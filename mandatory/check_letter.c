/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:21:23 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/18 17:06:56 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ERR_P "Error: The map must contain exactly one starting position (P).\n"
#define ERR_E "Error: The map must contain exactly one exit (E).\n"
#define ERR_C "Error: The map must contain at least one collectible (C).\n"
#define ERR_CHARA "Error: The map contains invalid characters.\n"

static int	check_letter_p(char *map)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			p++;
		i++;
	}
	if (p != 1)
		return (ft_printf(ERR_P), 1);
	return (0);
}

static int	check_letter_e(char *map)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			e++;
		i++;
	}
	if (e != 1)
		return (ft_printf(ERR_E), 1);
	return (0);
}

static int	check_letter_c(t_data *data, char *map)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			c++;
		i++;
	}
	if (c == 0)
		return (ft_printf(ERR_C), 1);
	data->total_collectibles = c;
	return (0);
}

int	check_letter(t_data *data, char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C' && map[i] != 'E'
			&& map[i] != 'P' && map[i] != '\n')
			return (ft_printf(ERR_CHARA), 1);
		i++;
	}
	if (check_letter_p(map) != 0 || check_letter_e(map) != 0
		|| check_letter_c(data, map) != 0)
		return (1);
	return (0);
}
