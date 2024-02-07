/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:48:50 by deordone          #+#    #+#             */
/*   Updated: 2024/02/07 10:22:32 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(t_map *checkmap, t_vector2d cor)
{
	if (cor.x < 0 || cor.x >= checkmap->width_map)
		return ;
	if (cor.y < 0 || cor.y >= checkmap->height_map)
		return ;
	if (checkmap->map[cor.y][cor.x] != SPACE
		&& checkmap->map[cor.y][cor.x] != PLAYER
		&& checkmap->map[cor.y][cor.x] != ITEM
		&& checkmap->map[cor.y][cor.x] != EXIT)
		return ;
	checkmap->map[cor.y][cor.x] = 'F';
	floodfill(checkmap, (t_vector2d){cor.x - 1, cor.y});
	floodfill(checkmap, (t_vector2d){cor.x + 1, cor.y});
	floodfill(checkmap, (t_vector2d){cor.x, cor.y - 1});
	floodfill(checkmap, (t_vector2d){cor.x, cor.y + 1});
}

int	ft_slpath_exist(t_map *checkmap, t_vector2d cor)
{
	int	aux;

	aux = 0;
	while (checkmap->map[cor.y])
	{
		cor.x = 0;
		while (checkmap->map[cor.y][cor.x])
		{
			cor.x++;
			if (checkmap->map[cor.y][cor.x] == PLAYER
				|| checkmap->map[cor.y][cor.x] == EXIT
				|| checkmap->map[cor.y][cor.x] == ITEM)
				return (1);
		}
		cor.y++;
	}
	return (0);
}

char	**ft_matrizdup(const char **matriz)
{
	char **dup;
	int row;

	row = 0;
	while (matriz[row])
		row++;
	dup = malloc(sizeof(char *) * row + 1);
	if (!dup)
		return (NULL);
	row = -1;
	while (matriz[++row])
	{
		dup[row] = ft_strdup(matriz[row]);
		if (!dup[row])
		{
			ft_free_array(dup);
			return (NULL);
		}
	}
	dup[row] = NULL;
	return (dup);
}

int *ft_find_component(t_map *map, char c)
{
	int	y;
	int	x;
	static int rslt[2];

	y = 0;
	x = 0;
	while (map->map[y][x] != c)
	{
		++x;
		if (!map->map[y][x])
		{
			++y;
			x = 0;
		}
	}
	rslt[0] = x;
	rslt[1] = y;
	return (rslt);
}
