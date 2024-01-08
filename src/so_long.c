/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:46:12 by carmeno           #+#    #+#             */
/*   Updated: 2024/01/08 04:12:58 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_pixel_put(t_data_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->l_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data_img	img;

	mlx = mlx_init();
	if (!mlx)
		exit(1);
	img.img = mlx_new_image(mlx, 500, 500);
	if (!img.img)
		exit(1);
	mlx_win = mlx_new_window(mlx, 500, 500, "-Droied-");
	if (!mlx_win)
		exit(1);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_line, &img.endian);
	int y = 99;
	while (++y < 400)
	{
		int x = 99;
		while (++x < 400)
			my_pixel_put(&img, x, y, 0x0000FF00);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
