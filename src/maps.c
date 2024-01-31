/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:45:40 by deordone          #+#    #+#             */
/*   Updated: 2024/01/31 11:38:55 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_valid(t_map *checkmap, t_vector2d cor)
{
	// pasa el map como parametro en ft_is_valid en vez del checkmap y aqui te haces tu duplicado del map y pues lo guardas en checkmap
	floodfill(checkmap, cor);
	ft_slpath_exist(checkmap, (t_vector2d){0, 0});
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
	if (keeper[1] < 1 || keeper[2] < 1)
		ft_map_error(map, "so long : no exit or no collectibles\n");
}

void	ft_is_closemap(t_map *map)
{
	t_map	checkmap;
	int		y;
	int		x;

	y = 0;
	x = 0;
	if (ft_check_horizontal_map(map) == 1 || ft_check_vertical_map(map) == 1)
		ft_map_error(map, "so_long : unclosed map\n");
	ft_map_components(map);
	checkmap = *map;
	while (checkmap.map[y][x] != PLAYER)
	{
		x++;
		if (!checkmap.map[y][x])
		{
			y++;
			x = 0;
		}
	}
	ft_is_valid(&checkmap, (t_vector2d){x, y});
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

void	ft_map_existence(char **argv)
{
	t_map	map;
	int		l_mapath;

	l_mapath = ft_strlen(argv[1]);
	l_mapath -= 4;
	if (ft_strncmp(&argv[1][l_mapath], ".ber", 4) != 0)
		ft_sl_error("so_long : invalid map\n");
	ft_init_map(&map);
	map.fd_map = open(argv[1], O_RDONLY);
	if (!map.fd_map)
		ft_sl_error("so_long : bad file descriptor\n");
	else
		ft_create_map(&map, map.fd_map);
}
