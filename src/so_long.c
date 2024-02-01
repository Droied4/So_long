/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:46:04 by deordone          #+#    #+#             */
/*   Updated: 2024/02/01 19:09:01 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_movement(t_map *map)
{
	//	while (1)
	//	{
	//		if ()
	//	}
	/*
		* si (presiona una tecla)
		* 	desplace la P con un swap y imprima el mapa
		* */
	ft_printf("x -> %i\n", map->player.x);
	ft_printf("y -> %i\n", map->player.y);
	return ;
}

int	endgame(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		printf("csitas%p\n", mlx->mlx);
//		mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx 	mlx;
	t_img	img;
	t_map	map;

	if (argc != 2)
		ft_sl_error("so_long : two arguments are needed\n");
	ft_map_existence(argv, &map);
	//	ft_player_movement(&map);
	ft_printf("OK\n");
	img.width = 16;
	img.height = 16;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		exit(1);
	mlx.win = mlx_new_window(mlx.mlx, 500, 500, "-Droied-");
	if (!mlx.win)
		exit(1);
	img.image = mlx_xpm_file_to_image(mlx.mlx, SPACE_PATH, &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.image, &img.bpp, &img.l_line, &img.endian);
	if (img.image == NULL)
		printf("Error al cargar la imagen desde el archivo XPM.\n");
	else
	{
		mlx_put_image_to_window(mlx.mlx, mlx.win, img.image, 100, 100);
		mlx_put_image_to_window(mlx.mlx, mlx.win, img.image, 116, 108);
		mlx_put_image_to_window(mlx.mlx, mlx.win, img.image, 132, 116);
		mlx_put_image_to_window(mlx.mlx, mlx.win, img.image, 148, 124);
	}
	mlx_hook(mlx.win, ESC, 0, endgame, &mlx);
	//mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
