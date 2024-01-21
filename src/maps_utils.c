/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:14:26 by deordone          #+#    #+#             */
/*   Updated: 2024/01/21 13:16:22 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:11:00 by deordone          #+#    #+#             */
/*   Updated: 2024/01/21 13:14:24 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_horizontal_map(t_map *map)
{
	int	i;
	int	j;
	int	h;

	h = 0;
	i = -1;
	j = 0;
	while (++h < 2)
	{
		while (map->map[j][++i])
		{
			if (map->map[j][i] != '1' && map->map[j][i] != '\0')
				return (1);
		}
		j = map->height_map;
		i = -1;
	}
	return (0);
}

int	ft_check_vertical_map(t_map *map)
{
	int	i;
	int	j;
	int	h;

	h = 0;
	i = 0;
	j = -1;
	while (++h < 2)
	{
		while (map->map[++j][i])
		{
			if (map->map[j][i] != '1' && map->map[j][i] != '\0')
				return (1);
		}
		i = map->width_map;
		j = -1;
	}
	return (0);
}

void	ft_check_rectangularmap(t_map *map)
{
	int l_line;
	l_line = map->height_map / map->bytes_map;
	if (map->width_map != l_line)
		ft_sl_error("so_long : non-rectangular map\n");
}

void	ft_init_map(t_map *map)
{
	map->map = NULL;
	map->height_map = -1;
	map->width_map = -1;
	map->bytes_map = -1;
	map->fd_map = -1;
}
