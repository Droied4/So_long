/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aprender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:46:42 by deordone          #+#    #+#             */
/*   Updated: 2024/01/21 15:43:50 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_line + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

//algoritmo dda
void	dda_line(t_img img, t_vector2d p1, t_vector2d p2)
{
	double x, y, dx, dy, p, xi, yi, k;
	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	if (dx > dy)
		p = dx;
	else
		p = dy;
	xi = dx / p;
	yi = dy / p;
	if (p1.x > p2.x)
		xi *= (-1);
	if (p1.y > p2.y)
		yi *= (-1);
	x = p1.x;
	y = p1.y;
	for (k = 1; k <= p; k++)
	{
		x += xi;
		y += yi;
		my_pixel_put(&img, x, y, 0x008A2BE2);
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	if (!mlx)
		exit(1);
	mlx_win = mlx_new_window(mlx, 500, 500, "-Droied-");
	if (!mlx_win)
		exit(1);
	img.image = mlx_new_image(mlx, 500, 500);
	if (!img.image)
		exit(1);
	img.addr = mlx_get_data_addr(img.image, &img.bpp, &img.l_line, &img.endian);
	//draw_triangle(img);
	//draw_cube(img);
	int circle_center_x = 200;
    	int circle_center_y = 200;

    	draw_circle(img, circle_center_x, circle_center_y, 100);
    	draw_circle(img, circle_center_x, circle_center_y, 75);
    	draw_circle(img, circle_center_x, circle_center_y, 50);
    	draw_circle(img, circle_center_x, circle_center_y, 25);
	while (1)
		mlx_put_image_to_window(mlx, mlx_win, img.image, 0, 0);
	mlx_loop(mlx);
	return (0);
}
