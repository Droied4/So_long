/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:48:50 by deordone          #+#    #+#             */
/*   Updated: 2024/01/30 19:14:09 by deordone         ###   ########.fr       */
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
	/*	ft_dprintf(2, "\n");
		ft_dprintf(2, "%s\n", checkmap->map[0]);
		ft_dprintf(2, "%s\n", checkmap->map[1]);
		ft_dprintf(2, "%s\n", checkmap->map[2]);
		ft_dprintf(2, "%s\n", checkmap->map[3]);
		ft_dprintf(2, "%s\n", checkmap->map[4]);
		ft_dprintf(2, "%s\n", checkmap->map[5]);*/
	floodfill(checkmap, (t_vector2d){cor.x - 1, cor.y});
	floodfill(checkmap, (t_vector2d){cor.x + 1, cor.y});
	floodfill(checkmap, (t_vector2d){cor.x, cor.y - 1});
	floodfill(checkmap, (t_vector2d){cor.x, cor.y + 1});
}

void	ft_slpath_exist(t_map *checkmap, t_vector2d cor)
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
				aux++;
		}
		cor.y++;
	}
	if (aux >= 1)
		ft_map_error(checkmap, "so_long: there is no possible path\n");
}
