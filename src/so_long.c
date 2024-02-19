/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:46:04 by deordone          #+#    #+#             */
/*   Updated: 2024/02/19 12:00:56 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_cheems(t_mlx *mlx)
{
	t_img	photo;

	photo.width = SPRITE_SIZE;
	photo.height = SPRITE_SIZE;
	photo.image = mlx_xpm_file_to_image(mlx->mlx, CHEEMS_PATH, &photo.width,
			&photo.height);
	if (photo.image == NULL)
	{
		ft_dprintf(2, "Error al cargar la imagen desde el archivo .XPM");
		exit(1);
	}
	photo.addr = mlx_get_data_addr(photo.image, &photo.bpp, &photo.l_line,
			&photo.endian);
	ft_dprintf(2, "Cheems\n");
	mlx_put_image_to_window(mlx->mlx, mlx->win, photo.image, mlx->screen_width
		/ 2, 0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		ft_sl_error("so_long : two arguments are needed\n");
	ft_map_existence(argv, &mlx.map);
	ft_win_size(&mlx);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		exit(1);
	mlx.mov = 0;
	mlx.win = mlx_new_window(mlx.mlx, mlx.screen_width, mlx.screen_height,
			"-Droied-");
	if (!mlx.win)
		exit(1);
	if (ft_strncmp(argv[1], "Cheems.ber", 9) == 0)
		put_cheems(&mlx);
	ft_render_daddy(&mlx, 0);
	mlx_hook(mlx.win, 2, 0, ft_event_listener, &mlx);
	mlx_hook(mlx.win, 17, 0L, ft_destroy_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
