/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:50:21 by deordone          #+#    #+#             */
/*   Updated: 2024/09/24 19:42:32 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_STRUCT_H
# define SL_STRUCT_H

typedef struct s_vector2d
{
	int			x;
	int			y;
}				t_vector2d;

typedef struct s_map
{
	char		**map;
	int			height_map;
	int			width_map;
	int			bytes_map;
	int			fd_map;
	int			max_items;
	t_vector2d	player;
}				t_map;

typedef struct s_mlx
{

	mlx_t		*mlx;
	mlx_image_t	*img;
	int			mov;
	t_map		map;
	int			screen_width;
	int			screen_height;
}				t_mlx;

typedef struct s_img
{
	void		*image;
	char		*addr;
	int			bpp;
	int			l_line;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_sprites
{
	t_img		wall;
	t_img		space;
	t_img		player_up;
	t_img		player_down;
	t_img		player_right;
	t_img		player_left;
	t_img		item;
	t_img		exit;
	int			dir;
}				t_sprites;
#endif
