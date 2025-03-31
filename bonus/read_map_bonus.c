/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:42:58 by yookamot          #+#    #+#             */
/*   Updated: 2025/02/22 14:20:07 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

#define ERR_REC "Error: The map is not rectangular.\n"

static int	file_check(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] != 'r' || file[len - 2] != 'e' || file[len - 3] != 'b'
		|| file[len - 4] != '.')
		return (1);
	return (0);
}

static char	*read_line(char *map, int fd)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = map;
		map = ft_strjoin(map, line);
		free(temp);
		free(line);
		if (!map)
			return (NULL);
		line = get_next_line(fd);
	}
	if (map[ft_strlen(map) - 1] == '\n')
		return (ft_printf(ERR_REC), free(map), NULL);
	return (map);
}

void	read_map(t_data *data, char *file)
{
	int		fd;
	char	*line;
	char	*map;
	char	*temp;

	if (file_check(file) != 0)
	{
		ft_printf("Error: \"%s\" is not a .ber file.\n", file);
		exit(1);
	}
	map = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (!map || fd < 0)
		exit(1);
	map = read_line(map, fd);
	close(fd);
	if (!map)
		exit(1);
	if (check_map(data, map) != 0)
		return (free(map), exit(1));
	data->map = ft_split(map, '\n');
	free(map);
	if (!data->map)
		exit(1);
	search_valid_path(data);
}
