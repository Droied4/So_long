/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:46:04 by deordone          #+#    #+#             */
/*   Updated: 2024/01/31 13:01:54 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_movement(t_map *map)
{
	ft_printf("x -> %i\n", map->player.x);	
	ft_printf("y -> %i\n", map->player.y);	
	return ;
}

int	main(int argc, char **argv)
{
	//void		*mlx;
	//void		*mlx_win;
	//int		width;
	//int		height;
	//t_img		img;
	//char	*path;
	t_map map;

	if (argc != 2)
		ft_sl_error("so_long : two arguments are needed\n");
	ft_map_existence(argv, &map);
	ft_player_movement(&map);
	ft_printf("OK\n");
	return (0);
	/*
		width = 32;
		height = 32;
		path = "./sprites/start.xpm";
		mlx = mlx_init();
		if (!mlx)
			exit(1);
		mlx_win = mlx_new_window(mlx, 500, 500, "-Droied-");
		if (!mlx_win)
			exit(1);
		img.image = mlx_xpm_file_to_image(mlx, path, &width, &height);
		img.addr = mlx_get_data_addr(img.image, &img.bpp, &img.l_line,
				&img.endian);
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
