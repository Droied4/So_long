/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:46:04 by deordone          #+#    #+#             */
/*   Updated: 2024/01/21 13:01:42 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_sl_error("so_long : two arguments are needed\n");
	ft_map_existence(argv);
	ft_printf("OK");
	return (0);
	/*
	void		*mlx;
	void		*mlx_win;
	int		width = 32;
	int		height = 32;
	t_img		img;
	char		*path = "./sprites/start.xpm";
	
	
	mlx = mlx_init();
	if (!mlx)
		exit(1);
	mlx_win = mlx_new_window(mlx, 500, 500, "-Droied-");
	if (!mlx_win)
		exit(1);
	img.image = mlx_xpm_file_to_image(mlx, path, &width, &height);
	img.addr = mlx_get_data_addr(img.image, &img.bpp, &img.l_line, &img.endian);
	if (img.image == NULL)
		printf("Error al cargar la imagen desde el archivo XPM.\n");
	else
	{
        	mlx_put_image_to_window(mlx, mlx_win, img.image, 100, 100);
        	mlx_put_image_to_window(mlx, mlx_win, img.image, 132, 116);
        	mlx_put_image_to_window(mlx, mlx_win, img.image, 164, 132);
        	mlx_put_image_to_window(mlx, mlx_win, img.image, 196, 148);
	}
	mlx_loop(mlx);
	return (0);
	*/
}
