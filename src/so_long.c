/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:46:12 by carmeno           #+#    #+#             */
/*   Updated: 2024/01/14 16:16:23 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->l_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
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
        	mlx_put_image_to_window(mlx, mlx_win, img.image, 110, 110);
	}	
	mlx_loop(mlx);
	return (0);
}
