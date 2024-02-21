/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:14:26 by deordone          #+#    #+#             */
/*   Updated: 2024/02/21 10:31:56 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win_size(t_mlx *mlx)
{
	if (mlx->map.height_map >= mlx->map.width_map)
		mlx->screen_width = (mlx->map.height_map * 32);
	else
		mlx->screen_width = (mlx->map.width_map * 32);
	mlx->screen_height = (mlx->map.width_map + mlx->map.height_map) * 8;
}

int	*ft_check_components(char pos, int *keeper)
{
	if (pos == PLAYER)
		keeper[0]++;
	else if (pos == ITEM)
		keeper[1]++;
	else if (pos == EXIT)
		keeper[2]++;
	else if (pos == WALL)
		keeper[3]++;
	else if (pos == SPACE)
		keeper[4]++;
	else
		ft_sl_error("so long : unreconigzed component\n");
	return (keeper);
}

int	ft_check_horizontal_map(t_map *map)
{
	int	i;
	int	j;
	int	h;

	h = -1;
	i = -1;
	j = 0;
	while (++h < 2)
	{
		while (map->map[j][++i] && map->map[j][i] != '\n')
		{
			if (map->map[j][i] != WALL && map->map[j][i] != '\0')
				return (1);
		}
		j = map->height_map - 1;
		i = -1;
	}
	return (0);
}

int	ft_check_vertical_map(t_map *map)
{
	int	i;
	int	j;
	int	h;

	h = -1;
	i = 0;
	j = -1;
	while (++h < 2)
	{
		while (map->map[++j] != NULL)
		{
			if (map->map[j][i] != WALL && map->map[j][i] != '\0')
				return (1);
		}
		i = map->width_map - 2;
		j = -1;
	}
	return (0);
}

void	ft_check_rectangularmap(t_map *map)
{
	int	l_line;

	l_line = map->bytes_map / map->height_map;
	if (map->width_map != l_line)
		ft_sl_error("so_long : non-rectangular map\n");
}
