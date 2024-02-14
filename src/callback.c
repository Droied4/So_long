/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:27:46 by deordone          #+#    #+#             */
/*   Updated: 2024/02/11 16:56:52 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_event_listener(int keycode, t_mlx *mlx)
{
	int aux;

	aux = 0;
	++mlx->mov;
	if (keycode == ESC)
	{
		ft_free_array(mlx->map.map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (keycode == LEFT_ARROW || keycode == A_BUTTON)
		aux = ft_player_right(&mlx->map);
	if (keycode == RIGHT_ARROW || keycode == D_BUTTON)
		aux = ft_player_left(&mlx->map);
	if (keycode == DOWN_ARROW || keycode == S_BUTTON)
		aux =ft_player_down(&mlx->map);
	if (keycode == UP_ARROW || keycode == W_BUTTON)
		aux = ft_player_up(&mlx->map);
	if (aux == 1)
		ft_event_listener(ESC, mlx);
	ft_render_daddy(mlx, NULL);
	ft_printf("\nMovements = %i\n", mlx->mov);
	ft_printf("\nCollectables = %i\n", mlx->map.max_items);
	return (0);
}
/* printear en terminal
	int i = -1;
	while (++i < mlx->map.height_map)
		ft_printf("%s\n", mlx->map.map[i]);*/

//mensaje para el deivid del futuro
//ya cambie las cosas buena suerte arreglando todas las mamadas que hice sin compilar en 42 hijo de puta
//falta lo del tamaño en el checkmap de utils1 y utils2 tienes espacio solo para 2 funciones mas
//creo que simplemente debes hacer una regla de 3 en la que si x tamaño es igual al 100% entonces con y
//tamaño cuanto seria creo que por ahi van los tiros 
//utiliza el bytes map creo que es la clave
//ahhh y falta hacer lo de los sprites que la verdad me da muchisima paja
//quisiera estar escrito en c para ser un puntero que apunte a tu corazon bb.
int	ft_sprite_dir(int keycode, t_mlx *mlx)
{
	int dir;
	if (keycode == ESC)
	{
		ft_free_array(mlx->map.map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (keycode == LEFT_ARROW || keycode == A_BUTTON)
		ft_render_daddy(mlx, PLAYER_LEFT_PATH);
	if (keycode == RIGHT_ARROW || keycode == D_BUTTON)
		ft_render_daddy(mlx, PLAYER_RIGHT_PATH);
	if (keycode == DOWN_ARROW || keycode == S_BUTTON)
		ft_render_daddy(mlx, PLAYER_DOWN_PATH);
	if (keycode == UP_ARROW || keycode == W_BUTTON)
		ft_render_daddy(mlx, PLAYER_UP_PATH);
}
