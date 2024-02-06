/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:47:52 by deordone          #+#    #+#             */
/*   Updated: 2024/02/06 17:27:23 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_image(t_mlx *mlx, t_sprites *spr, t_vector2d coor_win, t_vector2d coor_map)
{
	if (mlx->map.map[coor_map.y][coor_map.x] == WALL)
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->wall.image, coor_win.x, coor_win.y);
	else if (mlx->map.map[coor_map.y][coor_map.x] == SPACE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->space.image, coor_win.x, coor_win.y);
	else if (mlx->map.map[coor_map.y][coor_map.x] == PLAYER)
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->player.image, coor_win.x, coor_win.y);
	else if (mlx->map.map[coor_map.y][coor_map.x] == ITEM)
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->item.image, coor_win.x, coor_win.y);
	else if (mlx->map.map[coor_map.y][coor_map.x] == EXIT)
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->exit.image, coor_win.x, coor_win.y);
	//else
	//	return ;
	ft_dprintf(2,"y -> %i\nx -> %i\n", coor_map.y, coor_map.x);
	//ft_dprintf(2,"map -> %c\n", mlx->map.map[coor_map.y][coor_map.x]);
}

static void	ft_render_image(t_mlx *mlx, t_img *image)
{
	image->width = SPRITE_SIZE;
	image->height = SPRITE_SIZE;
	image->image = mlx_xpm_file_to_image(mlx->mlx, WALL_PATH, &image->width, &image->height);
	if (image->image == NULL)
		ft_dprintf(2, "Error al cargar la imagen desde el archivo .XPM\n");
	image->addr = mlx_get_data_addr(image->image, &image->bpp, &image->l_line, &image->endian);
}

void	ft_construct_image(t_mlx *mlx)
{
	t_sprites spr;
	int	i;
	int j;
	
	ft_render_image(mlx, &spr.wall);
	//ft_render_image(mlx, &spr.space, SPACE_PATH);
	//ft_render_image(mlx, &spr.player, PLAYER_PATH);
	//ft_render_image(mlx, &spr.item, ITEM_PATH);
	//ft_render_image(mlx, &spr.exit, EXIT_PATH);
	i = -1;
	while (mlx->map.map[++i] != NULL)
	{
		j = -1;
		while (mlx->map.map[i][++j] != '\0')
		{
			ft_put_image(mlx, &spr, (t_vector2d){SPRITE_SIZE, SCREEN_HEIGHT / 2}, (t_vector2d){j,i});
		}
	}
}
