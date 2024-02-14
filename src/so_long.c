/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:46:04 by deordone          #+#    #+#             */
/*   Updated: 2024/02/14 17:57:24 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_horse(t_mlx *mlx)
{
	t_img	photo;

	photo.width = SPRITE_SIZE;
	photo.height = SPRITE_SIZE;
	photo.image = mlx_xpm_file_to_image(mlx->mlx, horse_path * /, &photo.width,
			&photo.height);
	if (photo->image == NULL)
	{
		ft_dprintf(2, "Error al cargar la imagen desde el archivo .XPM");
		exit(1);
	}
	photo.addr = mlx_get_data_addr(photo.image, &photo.bpp, &image.l_line,
			&image.endian);
	while (1)
	{
		ft_dprintf(2, "Horse Supremacy");
		mlx_put_image_to_window(mlx->mlx, mlx->win, photo.image, SCREEN_WIDTH
			/ 2, SCREEN_HEIGHT / 2);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		ft_sl_error("so_long : two arguments are needed\n");
	ft_map_existence(argv, &mlx.map);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		exit(1);
	mlx.mov = 0;
	mlx.win = mlx_new_window(mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "-Droied-");
	if (!mlx.win)
		exit(1);
	if (ft_strncmp(argv[1], "Horse.ber") == 0)
		put_horse(mlx);
	ft_render_daddy(&mlx, NULL);
	mlx_hook(mlx.win, 2, 0, ft_sprite_dir, &mlx);
	mlx_hook(mlx.win, 2, 0, ft_event_listener, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
