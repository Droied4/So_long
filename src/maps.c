/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:45:40 by deordone          #+#    #+#             */
/*   Updated: 2024/02/14 17:58:24 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_valid(t_map *map, t_vector2d cor)
{
	t_map	checkmap;

	checkmap.map = ft_matrizdup((const char **)map->map);
	checkmap.width_map = map->width_map;
	checkmap.height_map = map->height_map;
	if (!checkmap.map)
		ft_map_error(map, "so_long: dup map failed\n");
	floodfill(&checkmap, cor);
	if (ft_slpath_exist(&checkmap, (t_vector2d){0, 0}) == 1)
	{
		ft_free_array(checkmap.map);
		ft_map_error(map, "so_long: there is no possible path\n");
	}
	ft_free_array(checkmap.map);
}

void	ft_map_components(t_map *map)
{
	int	i;
	int	j;
	int	*keeper;

	i = -1;
	keeper = ft_calloc(sizeof(int), 5);
	if (!keeper)
		ft_map_error(map, "so_long : memory reserve failed\n");
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			keeper = ft_check_components(map->map[i][j], keeper);
	}
	if (keeper[0] > 1)
		ft_map_error(map, "so long : more than one player\n");
	if (keeper[0] < 1 || keeper[1] < 1 || keeper[2] < 1 || keeper[3] < 1
		|| keeper[4] < 1)
		ft_map_error(map, "so long : a component is missing\n");
	map->max_items = keeper[1];
}

void	ft_is_closemap(t_map *map)
{
	int	*cor;

	if (ft_check_horizontal_map(map) == 1 || ft_check_vertical_map(map) == 1)
		ft_map_error(map, "so_long : unclosed map\n");
	ft_map_components(map);
	cor = ft_find_component(map, PLAYER);
	map->player.x = cor[0];
	map->player.y = cor[1];
	ft_is_valid(map, (t_vector2d){map->player.x, map->player.y});
}

void	ft_create_map(t_map *map, int fd)
{
	char	*line;
	char	*final_line;

	final_line = ft_calloc(sizeof(char), 1);
	if (!final_line)
		ft_map_error(map, "so_long : memory reserve failed\n");
	map->fd_map = fd;
	line = get_next_line(map->fd_map);
	if (!line)
		ft_map_error(map, "so_long : empty file\n");
	map->width_map = ft_strlen(line);
	while (line)
	{
		map->height_map++;
		map->bytes_map += ft_strlen(line);
		final_line = ft_strjoin(final_line, line);
		line = get_next_line(map->fd_map);
	}
	ft_check_rectangularmap(map);
	if (final_line)
		map->map = ft_split(final_line, '\n');
	else
		ft_map_error(map, "so_long : empty file\n");
	ft_is_closemap(map);
}

void	ft_map_existence(char **argv, t_map *map)
{
	int	l_mapath;

	l_mapath = ft_strlen(argv[1]);
	l_mapath -= 4;
	if (ft_strncmp(&argv[1][l_mapath], ".ber", 4) != 0)
		ft_sl_error("so_long : invalid map\n");
	map->fd_map = open(argv[1], O_RDONLY);
	if (!map->fd_map)
		ft_sl_error("so_long : bad file descriptor\n");
	else
		ft_create_map(map, map->fd_map);
}
