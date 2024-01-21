/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:45:40 by deordone          #+#    #+#             */
/*   Updated: 2024/01/21 15:43:36 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/*void	ft_is_validmap(t_map *map)
{
check the flood fill
}*/

//map_components check if exist all the components

void	ft_is_closemap(t_map *map)
{
	if (ft_check_horizontal_map(map) == 1 || ft_check_vertical_map(map) == 1)
		ft_map_error(map, "so_long : unclosed map\n");
	//ft_map_components(*/);
}

void ft_create_map(t_map *map, int fd)
{
	char *line;
	char *final_line;
	
	final_line = ft_calloc(1, 1);	
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
	t_map map;
	int l_mapath;
		
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
