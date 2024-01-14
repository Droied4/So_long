/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:56:25 by carmeno           #+#    #+#             */
/*   Updated: 2024/01/14 21:54:31 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_triangle(t_img img)
{
	t_vector2d p1 = {250, 50};
	t_vector2d p2 = {125, 200};
	t_vector2d p3 = {375, 200};

	dda_line(img, p1, p2);
	dda_line(img, p2, p3);
	dda_line(img, p3, p1);
}

void	draw_cube(t_img img)
{
	t_vector2d	p1 = {100, 100};
	t_vector2d	p2 = {250, 100};
	t_vector2d	p3 = {250, 250};
	t_vector2d	p4 = {100, 250};
	t_vector2d	p5 = {175, 50};
	t_vector2d	p6 = {325, 50};
	t_vector2d	p7 = {325, 212};

	dda_line(img, p1, p2);
	dda_line(img, p2, p3);
	dda_line(img, p3, p4);
	dda_line(img, p4, p1);
	dda_line(img, p1, p5);
	dda_line(img, p5, p6);
	dda_line(img, p6, p2);
	dda_line(img, p6, p7);
	dda_line(img, p7, p3);
}

static void	draw_circle_aux(t_img img, int xc, int yc, int x, int y)
{
	my_pixel_put(&img, xc + x, yc + y, 0xFFFFFF);
	my_pixel_put(&img, xc - x, yc + y, 0xFFFFFF);
	my_pixel_put(&img, xc + x, yc - y, 0xFFFFFF);
	my_pixel_put(&img, xc - x, yc - y, 0xFFFFFF);
	my_pixel_put(&img, xc + y, yc + x, 0xFFFFFF);
	my_pixel_put(&img, xc - y, yc + x, 0xFFFFFF);
	my_pixel_put(&img, xc + y, yc - x, 0xFFFFFF);
	my_pixel_put(&img, xc - y, yc - x, 0xFFFFFF);
}

void	draw_circle(t_img img, int xc, int yc, int radius)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = radius;
	d = 3 - 2 * radius;
	while (x <= y)
	{
		draw_circle_aux(img, xc, yc, x, y);
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
		{
			d = d + 4 * x + 6;
		}
		draw_circle_aux(img, xc, yc, x, y);
	}
}
