/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:46:04 by deordone          #+#    #+#             */
/*   Updated: 2024/09/24 20:09:16 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
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
}*/

static void game_init(void *param)
{
	t_mlx *core;

	core = (t_mlx *)param;
	ft_render_daddy(core, 0);
	ft_event_listener(core);
}

static void	begin_window(t_mlx *core, int32_t width, int32_t height)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(width, height, "So Long", 0);
	if (mlx == 0)
		ft_sl_error("so_long : mlx error\n");
	mlx_get_monitor_size(0, &width, &height);
	mlx_set_window_size(mlx, width, height);
	mlx_set_window_pos(mlx, 0, 0);
	image = mlx_new_image(mlx, width, height);
	if (image == 0 || (mlx_image_to_window(mlx, image, 0, 0)) < 0)
		ft_sl_error("so_long : mlx error\n");
	core->mlx = mlx;
	core->img = image;
}

int	main(int argc, char **argv)
{
	t_mlx	core;

	if (argc != 2)
		ft_sl_error("so_long : two arguments are needed\n");
	ft_map_existence(argv, &core.map);
	begin_window(&core, 1280, 960);
	// if (ft_strncmp(argv[1], "Cheems.ber", 9) == 0)
		// put_cheems(&mlx);
	mlx_loop_hook(core.mlx, game_init, &core);
	mlx_close_hook(core.mlx, (void (*)(void *))mlx_close_window, &core);
	mlx_loop(core.mlx);
	return (0);
}
