/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:46:04 by deordone          #+#    #+#             */
/*   Updated: 2024/02/07 11:22:49 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx 	mlx;

	if (argc != 2)
		ft_sl_error("so_long : two arguments are needed\n");
	ft_map_existence(argv, &mlx.map);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		exit(1);
	mlx.win = mlx_new_window(mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "-Droied-");
	if (!mlx.win)
		exit(1);
	else
	{
		ft_render_daddy(&mlx);
//		mlx_put_image_to_window(mlx.mlx, mlx.win, img.image, 100, 100);
//		mlx_put_image_to_window(mlx.mlx, mlx.win, img.image, 116, 108);
//		mlx_put_image_to_window(mlx.mlx, mlx.win, img.image, 132, 116);
//		mlx_put_image_to_window(mlx.mlx, mlx.win, img.image, 148, 124);
	}
	mlx_hook(mlx.win, 2, 0, ft_event_listener, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
