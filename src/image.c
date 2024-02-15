/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:47:52 by deordone          #+#    #+#             */
/*   Updated: 2024/02/15 16:16:18 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_player(t_mlx *mlx, t_sprites *spr, t_vector2d coor_win)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, spr->space.image, coor_win.x,
		coor_win.y);
	if (spr->dir == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->player_up.image,
			coor_win.x, coor_win.y - (SPRITE_SIZE/2));
	else if (spr->dir == 2)
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->player_down.image,
			coor_win.x, coor_win.y - (SPRITE_SIZE/2));
	else if (spr->dir == 3)
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->player_left.image,
			coor_win.x, coor_win.y - (SPRITE_SIZE/2));
	else if (spr->dir == 4)
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->player_right.image,
			coor_win.x, coor_win.y - (SPRITE_SIZE/2));
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->player_down.image,
			coor_win.x, coor_win.y - (SPRITE_SIZE/2));
}

static void	ft_put_image(t_mlx *mlx, t_sprites *spr, t_vector2d coor_win,
		t_vector2d coor_map)
{
	if (mlx->map.map[coor_map.y][coor_map.x] == WALL)
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->wall.image, coor_win.x,
			coor_win.y - (SPRITE_SIZE / 4));
	else if (mlx->map.map[coor_map.y][coor_map.x] == SPACE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->space.image,
			coor_win.x, coor_win.y);
	else if (mlx->map.map[coor_map.y][coor_map.x] == PLAYER)
		ft_put_player(mlx, spr, coor_win);
	else if (mlx->map.map[coor_map.y][coor_map.x] == ITEM)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->space.image,
			coor_win.x, coor_win.y);
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->item.image, coor_win.x,
			coor_win.y - SPRITE_SIZE);
	}
	else if (mlx->map.map[coor_map.y][coor_map.x] == EXIT)
		mlx_put_image_to_window(mlx->mlx, mlx->win, spr->exit.image, coor_win.x,
			coor_win.y - (SPRITE_SIZE / 2));
	else
		return ;
}

static void	ft_render_image(t_mlx *mlx, t_img *image, char *sprite_path)
{
	image->width = SPRITE_SIZE;
	image->height = SPRITE_SIZE;
	image->image = mlx_xpm_file_to_image(mlx->mlx, sprite_path, &image->width,
			&image->height);
	if (image->image == NULL)
		ft_dprintf(2, "Error al cargar la imagen desde el archivo .XPM\n");
	image->addr = mlx_get_data_addr(image->image, &image->bpp, &image->l_line,
			&image->endian);
}

void	ft_render_daddy(t_mlx *mlx, int play_dir)
{
	t_sprites	spr;

	ft_render_image(mlx, &spr.wall, WALL_PATH);
	ft_render_image(mlx, &spr.space, SPACE_PATH);
	ft_render_image(mlx, &spr.player_up, PLAYER_UP_PATH);
	ft_render_image(mlx, &spr.player_down, PLAYER_DOWN_PATH);
	ft_render_image(mlx, &spr.player_right, PLAYER_RIGHT_PATH);
	ft_render_image(mlx, &spr.player_left, PLAYER_LEFT_PATH);
	ft_render_image(mlx, &spr.item, ITEM_PATH);
	ft_render_image(mlx, &spr.exit, EXIT_PATH);
	if (play_dir == 1)
		spr.dir = 1;
	else if (play_dir == 2)
		spr.dir = 2;
	else if (play_dir == 3)
		spr.dir = 3;
	else if (play_dir == 4)
		spr.dir = 4;
	else
		spr.dir = 0;
	ft_construct_image(mlx, &spr);
}

void	ft_construct_image(t_mlx *mlx, t_sprites *spr)
{
	t_vector2d	iter;
	t_vector2d	my;
	t_vector2d	pos;
	t_vector2d	temp;

	temp.x = 0;
	temp.y = 0;
	iter.x = -1;
	while (mlx->map.map[++iter.x] != NULL)
	{
		pos.x = (SCREEN_WIDTH / 2) + temp.x;
		pos.y = temp.y;
		temp.x += SPRITE_SIZE;
		temp.y += SPRITE_SIZE / 2;
		my.x = SPRITE_SIZE;
		my.y = SPRITE_SIZE / 2;
		iter.y = -1;
		while (mlx->map.map[iter.x][++iter.y] != '\0')
		{
			ft_put_image(mlx, spr, (t_vector2d){pos.x - my.x, pos.y + my.y},
				(t_vector2d){iter.y, iter.x});
			my.x += SPRITE_SIZE;
			my.y += SPRITE_SIZE / 2;
		}
	}
}
