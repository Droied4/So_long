/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:27:46 by deordone          #+#    #+#             */
/*   Updated: 2024/02/04 16:50:19 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_event_listener(int keycode, t_mlx *mlx)
{
	int aux;

	aux = 0;
	if (keycode == ESC)
	{
		ft_free_array(mlx->map.map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (keycode == LEFT_ARROW || keycode == A_BUTTON)
		aux = ft_player_left(&mlx->map);
	if (keycode == RIGHT_ARROW || keycode == D_BUTTON)
		aux = ft_player_right(&mlx->map);
	if (keycode == DOWN_ARROW || keycode == S_BUTTON)
		aux =ft_player_down(&mlx->map);
	if (keycode == UP_ARROW || keycode == W_BUTTON)
		aux = ft_player_up(&mlx->map);
	if (aux == 1)
		ft_event_listener(ESC, mlx);
	int i = -1;
	while (++i < mlx->map.height_map)
		ft_printf("%s\n", mlx->map.map[i]);
	ft_printf("\nCollectables = %i\n", mlx->map.max_items);
	return (0);
}
