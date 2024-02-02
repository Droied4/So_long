/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:21:44 by deordone          #+#    #+#             */
/*   Updated: 2024/02/02 17:52:48 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_player_left(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->height_map)
		ft_printf("%s\n", map->map[i]);
	ft_printf("\n");
	// Coordenadas de P
	// Dependiendo de la tecla hago el movimiento si es un 0 se puede si es un WALL o EXIT no se puede
}

static void	ft_player_right(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->height_map)
		ft_printf("%s\n", map->map[i]);
	ft_printf("\n");
}

static void	ft_player_up(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->height_map)
		ft_printf("%s\n", map->map[i]);
	ft_printf("\n");
}

static void	ft_player_down(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->height_map)
		ft_printf("%s\n", map->map[i]);
	ft_printf("\n");
}

int	ft_event_listener(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (keycode == LEFT_ARROW || keycode == A_BUTTON)
		ft_player_left(&mlx->map);
	if (keycode == RIGHT_ARROW || keycode == D_BUTTON)
		ft_player_right(&mlx->map);
	if (keycode == DOWN_ARROW || keycode == S_BUTTON)
		ft_player_down(&mlx->map);
	if (keycode == UP_ARROW || keycode == W_BUTTON)
		ft_player_up(&mlx->map);
	return (0);
}
