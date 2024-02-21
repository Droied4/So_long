/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:21:44 by deordone          #+#    #+#             */
/*   Updated: 2024/02/21 10:31:29 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_item(t_map *map)
{
	map->map[map->player.y][map->player.x] = SPACE;
	--map->max_items;
}

int	ft_player_left(t_map *map, t_mlx *mlx)
{
	char	temp;

	if (map->map[map->player.y][map->player.x - 1] != WALL
		&& (map->map[map->player.y][map->player.x - 1] != EXIT
			|| map->max_items <= 0))
	{
		temp = map->map[map->player.y][map->player.x];
		if (map->map[map->player.y][map->player.x - 1] == EXIT
			&& map->max_items <= 0)
			return (1);
		if (map->map[map->player.y][map->player.x - 1] == ITEM)
			ft_item(map);
		else
			map->map[map->player.y][map->player.x] = \
				map->map[map->player.y][map->player.x - 1];
		map->map[map->player.y][map->player.x - 1] = temp;
		map->player.x -= 1;
		++mlx->mov;
	}
	return (0);
}

int	ft_player_right(t_map *map, t_mlx *mlx)
{
	char	temp;

	if (map->map[map->player.y][map->player.x + 1] != WALL
		&& (map->map[map->player.y][map->player.x + 1] != EXIT
			|| map->max_items <= 0))
	{
		temp = map->map[map->player.y][map->player.x];
		if (map->map[map->player.y][map->player.x + 1] == EXIT
			&& map->max_items <= 0)
			return (1);
		if (map->map[map->player.y][map->player.x + 1] == ITEM)
			ft_item(map);
		else
			map->map[map->player.y][map->player.x] = \
				map->map[map->player.y][map->player.x + 1];
		map->map[map->player.y][map->player.x + 1] = temp;
		map->player.x += 1;
		++mlx->mov;
	}
	return (0);
}

int	ft_player_up(t_map *map, t_mlx *mlx)
{
	char	temp;

	if (map->map[map->player.y - 1][map->player.x] != WALL
		&& (map->map[map->player.y - 1][map->player.x] != EXIT
			|| map->max_items <= 0))
	{
		temp = map->map[map->player.y][map->player.x];
		if (map->map[map->player.y - 1][map->player.x] == EXIT
			&& map->max_items <= 0)
			return (1);
		if (map->map[map->player.y - 1][map->player.x] == ITEM)
			ft_item(map);
		else
			map->map[map->player.y][map->player.x] = map->map[map->player.y
				- 1][map->player.x];
		map->map[map->player.y - 1][map->player.x] = temp;
		map->player.y -= 1;
		++mlx->mov;
	}
	return (0);
}

int	ft_player_down(t_map *map, t_mlx *mlx)
{
	char	temp;

	if (map->map[map->player.y + 1][map->player.x] != WALL
		&& (map->map[map->player.y + 1][map->player.x] != EXIT
			|| map->max_items <= 0))
	{
		temp = map->map[map->player.y][map->player.x];
		if (map->map[map->player.y + 1][map->player.x] == EXIT
			&& map->max_items <= 0)
			return (1);
		if (map->map[map->player.y + 1][map->player.x] == ITEM)
			ft_item(map);
		else
			map->map[map->player.y][map->player.x] = map->map[map->player.y
				+ 1][map->player.x];
		map->map[map->player.y + 1][map->player.x] = temp;
		map->player.y += 1;
		++mlx->mov;
	}
	return (0);
}
