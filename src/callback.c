/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:27:46 by deordone          #+#    #+#             */
/*   Updated: 2024/02/19 12:23:09 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy_window(t_mlx *mlx)
{
		ft_free_array(&mlx->map.map);
		close(mlx->map.fd_map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
}

int	ft_event_listener(int keycode, t_mlx *mlx)
{
	int	aux;

	aux = 0;
	if (keycode == ESC)
		ft_destroy_window(mlx);
	if (keycode == LEFT_ARROW || keycode == A_BUTTON)
		aux = ft_player_right(&mlx->map, mlx);
	if (keycode == RIGHT_ARROW || keycode == D_BUTTON)
		aux = ft_player_left(&mlx->map, mlx);
	if (keycode == DOWN_ARROW || keycode == S_BUTTON)
		aux = ft_player_down(&mlx->map, mlx);
	if (keycode == UP_ARROW || keycode == W_BUTTON)
		aux = ft_player_up(&mlx->map, mlx);
	if (aux == 1)
		ft_event_listener(ESC, mlx);
	ft_sprite_dir(keycode, mlx);
	ft_dprintf(2,"key = %i\n", keycode);
	ft_printf("\nMovements = %i\n", mlx->mov);
	ft_printf("\nCollectables = %i\n", mlx->map.max_items);
	return (0);
}

int	ft_sprite_dir(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		ft_destroy_window(mlx);
	if (keycode == LEFT_ARROW || keycode == A_BUTTON)
		ft_render_daddy(mlx, 3);
	if (keycode == RIGHT_ARROW || keycode == D_BUTTON)
		ft_render_daddy(mlx, 4);
	if (keycode == DOWN_ARROW || keycode == S_BUTTON)
		ft_render_daddy(mlx, 2);
	if (keycode == UP_ARROW || keycode == W_BUTTON)
		ft_render_daddy(mlx, 1);
	return (0);
}
