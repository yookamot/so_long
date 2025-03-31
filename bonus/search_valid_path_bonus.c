/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_valid_path_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:56:40 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/18 17:08:55 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map_and_exit_game(t_data *data, char **map)
{
	if (map)
		free_array(map);
	exit_game(data, 1);
}

char	**copy_map(t_data *data, char **map)
{
	int		i;
	char	**cp_map;

	i = 0;
	while (map[i])
		i++;
	cp_map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!cp_map)
		free_map_and_exit_game(data, NULL);
	i = 0;
	while (map[i])
	{
		cp_map[i] = ft_strdup(map[i]);
		if (!cp_map[i])
			free_map_and_exit_game(data, cp_map);
		i++;
	}
	cp_map[i] = NULL;
	return (cp_map);
}

int	search_p(char **cp_map)
{
	int	i;
	int	j;

	i = 0;
	while (cp_map[i])
	{
		j = 0;
		while (cp_map[i][j])
		{
			if (cp_map[i][j] == 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static char	**modify_map(char **cp_map, int count, t_data *data)
{
	char	**modified_map;
	int		i;
	int		j;
	int		modify_count;

	modified_map = copy_map(data, cp_map);
	i = 0;
	modify_count = 0;
	while (modified_map[i])
	{
		j = 0;
		while (modified_map[i][j])
		{
			if (modified_map[i][j] == 'C')
			{
				modify_count++;
				if (count != modify_count)
					modified_map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (modified_map);
}

#define ERR_E "Error: No valid path to exit.\n"
#define ERR_C "Error: No valid path to collectible.\n"

void	search_valid_path(t_data *data)
{
	int		count;
	char	**cp_map;
	char	**modified_map;
	int		invalid_count;

	count = 0;
	invalid_count = 0;
	cp_map = copy_map(data, data->map);
	if (search_valid_path_to_exit(cp_map) != 0)
		return (ft_printf(ERR_E), free_map_and_exit_game(data, cp_map));
	free_array(cp_map);
	while (count < data->total_collectibles)
	{
		modified_map = modify_map(data->map, count + 1, data);
		if (search_valid_path_to_collectible(modified_map) != 0)
			invalid_count++;
		free_array(modified_map);
		count++;
	}
	if (invalid_count != 0)
		return (ft_printf(ERR_C), exit_game(data, 1));
}
