/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:27:46 by deordone          #+#    #+#             */
/*   Updated: 2024/09/24 20:11:44 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy_window(t_mlx *core)
{
	ft_free_array(&core->map.map);
	close(core->map.fd_map);
	mlx_close_window(core->mlx);
	exit(0);
}

int	ft_event_listener(t_mlx *mlx)
{
	int	aux;

	aux = 0;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_ESCAPE))
		ft_destroy_window(mlx);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_UP) || mlx_is_key_down(mlx->mlx, MLX_KEY_W))
		aux = ft_player_up(&mlx->map, mlx);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx->mlx, MLX_KEY_S))
		aux = ft_player_down(&mlx->map, mlx);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_A) || mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
		aux = ft_player_right(&mlx->map, mlx);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_D) || mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT))
		aux = ft_player_left(&mlx->map, mlx);
	if (aux == 1)
		ft_destroy_window(mlx);
	ft_sprite_dir(mlx);
	ft_printf("\nMovements = %i\n", mlx->mov);
	ft_printf("\nCollectables = %i\n", mlx->map.max_items);
	return (0);
}

int	ft_sprite_dir(t_mlx *mlx)
{
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_ESCAPE))
		ft_destroy_window(mlx);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_UP) || mlx_is_key_down(mlx->mlx, MLX_KEY_W))
		ft_render_daddy(mlx, 1);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx->mlx, MLX_KEY_S))
		ft_render_daddy(mlx, 2);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_A) || mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
		ft_render_daddy(mlx, 3);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_D) || mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT))
		ft_render_daddy(mlx, 4);
	return (0);
}
