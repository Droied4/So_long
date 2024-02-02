/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:46:04 by deordone          #+#    #+#             */
/*   Updated: 2024/02/02 17:32:07 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx 	mlx;
	t_img	img;

	if (argc != 2)
		ft_sl_error("so_long : two arguments are needed\n");
	ft_map_existence(argv, &mlx.map);
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
	mlx_hook(mlx.win, 2, 0, ft_event_listener, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
