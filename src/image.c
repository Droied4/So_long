/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:47:52 by deordone          #+#    #+#             */
/*   Updated: 2024/02/07 13:42:26 by deordone         ###   ########.fr       */
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
	//ft_dprintf(2,"y -> %i\nx -> %i\n", coor_map.y, coor_map.x);
	//ft_dprintf(2,"map -> %c\n", mlx->map.map[coor_map.y][coor_map.x]);
}

static void	ft_render_image(t_mlx *mlx, t_img *image, char *sprite_path)
{
	image->width = SPRITE_SIZE;
	image->height = SPRITE_SIZE;
	image->image = mlx_xpm_file_to_image(mlx->mlx, sprite_path, &image->width, &image->height);
	if (image->image == NULL)
		ft_dprintf(2, "Error al cargar la imagen desde el archivo .XPM\n");
	image->addr = mlx_get_data_addr(image->image, &image->bpp, &image->l_line, &image->endian);
}

void	ft_render_daddy(t_mlx *mlx)
{	
	t_sprites spr;

	ft_render_image(mlx, &spr.wall, WALL_PATH);
	ft_render_image(mlx, &spr.space, SPACE_PATH);
	ft_render_image(mlx, &spr.player, PLAYER_PATH);
	ft_render_image(mlx, &spr.item, ITEM_PATH);
	ft_render_image(mlx, &spr.exit, EXIT_PATH);
/*	mlx_put_image_to_window(mlx->mlx, mlx->win, spr.space.image, SCREEN_WIDTH / 2, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, spr.space.image, ((SCREEN_WIDTH / 2) - 16), 8);
	mlx_put_image_to_window(mlx->mlx, mlx->win, spr.space.image, ((SCREEN_WIDTH / 2) - 32), 16);
	mlx_put_image_to_window(mlx->mlx, mlx->win, spr.space.image, ((SCREEN_WIDTH / 2) - 48), 24);
	mlx_put_image_to_window(mlx->mlx, mlx->win, spr.space.image, ((SCREEN_WIDTH / 2) - 64), 32);
	mlx_put_image_to_window(mlx->mlx, mlx->win, spr.space.image, ((SCREEN_WIDTH / 2) - 80), 40);
	mlx_put_image_to_window(mlx->mlx, mlx->win, spr.space.image, ((SCREEN_WIDTH / 2) + 16), 8);
	mlx_put_image_to_window(mlx->mlx, mlx->win, spr.space.image, (SCREEN_WIDTH / 2), 16);
	mlx_put_image_to_window(mlx->mlx, mlx->win, spr.space.image, (SCREEN_WIDTH / 2) - 16, 24);*/

	ft_construct_image(mlx, &spr);
}

void	ft_construct_image(t_mlx *mlx, t_sprites *spr)
{
	int	i;
	int j;
	int	my_x;
	int	my_y;
	int pos_x;
	int pos_y;
	int temp_x;
	int temp_y;
	
	my_x = SPRITE_SIZE; //16
	my_y = SPRITE_SIZE/2; //8
	pos_x = SCREEN_WIDTH/2; //la mitad de la pantalla en x
	pos_y = 0; //el inicio de la pantalla en y
	temp_x = 0;
	temp_y = 0;
	i = -1;
	while (mlx->map.map[++i] != NULL)
	{
		pos_x = (SCREEN_WIDTH / 2) + temp_x;
		pos_y = temp_y;
		temp_x += SPRITE_SIZE;
		temp_y += SPRITE_SIZE / 2;
		j = -1;
		ft_dprintf(2,"Horse\n");
		while (mlx->map.map[i][++j] != '\0')
		{
		ft_dprintf(2,"pos_x -> %i\n", pos_x - my_x);
		ft_dprintf(2,"pos_y -> %i\n", pos_y + my_y);
			ft_put_image(mlx, spr, (t_vector2d){pos_x - my_x, pos_y + my_y}, (t_vector2d){j,i});
			my_x += SPRITE_SIZE;
			my_y += SPRITE_SIZE/2;
		}
	}
}
