/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:46:45 by carmeno           #+#    #+#             */
/*   Updated: 2024/01/19 13:56:59 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../library/libft/libft.h"
//# include "../library/minilibx_linux/mlx.h"
# include "../library/minilibx_mac/mlx.h"
# include "../library/printf/ft_printf.h"
//# include "sprites.h"
/*Datos para las imagenes*/
typedef struct s_img
{
	void		*image;
	char		*addr;
	int		bpp;
	int		l_line;
	int		endian;
}			t_img;

typedef struc s_map
{
	char	**map;
	int		height_map;
	int		width_map;
	int		fd_map;
}			t_map;

typedef struct s_vector2d {
	int	x;
	int	y;
}		t_vector2d;

typedef struct s_colors
{
	int		red;
	int		green;
	int		blue;
	int		black;
	int		white;
	int		yellow;
	int		magenta;
	int		cyan;
	int		brown;
	int		orange;
	int		purple;
}			t_colors;

/*
 *	SHAPES
 *
 * */

void	draw_triangle (t_img);
void	draw_cube (t_img);
void	draw_circle(t_img img, int center_x, int center_y, int radius);

/*
 *
 *	ALGORITMOS
 *
 * */

void    dda_line(t_img img, t_vector2d p1, t_vector2d p2);

/*
 *
 * UTILS
 *
 * */

void    my_pixel_put(t_img *data, int x, int y, int color);


#endif
