/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:46:45 by carmeno           #+#    #+#             */
/*   Updated: 2024/02/15 16:05:52 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../library/ft_dprintf/ft_dprintf.h"
# include "../library/get_next_line/get_next_line.h"
# include "../library/libft/libft.h"
# include "../library/minilibx_mac/mlx.h"
# include "../library/printf/ft_printf.h"

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define SPRITE_SIZE 16
# define SPACE '0'
# define SPACE_PATH "./textures/space.xpm"
# define WALL '1'
# define WALL_PATH "./textures/wall.xpm"
# define ITEM 'C'
# define ITEM_PATH "./textures/item.xpm"
# define EXIT 'E'
# define EXIT_PATH "./textures/exit.xpm"
# define PLAYER 'P'
# define PLAYER_UP_PATH "./textures/player_up.xpm"
# define PLAYER_DOWN_PATH "./textures/player_down.xpm"
# define PLAYER_LEFT_PATH "./textures/player_right.xpm"
# define PLAYER_RIGHT_PATH "./textures/player_right.xpm"
# define HORSE_PATH "./textures/horse.xpm"
# define ESC 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126
# define A_BUTTON 0
# define D_BUTTON 2
# define S_BUTTON 1
# define W_BUTTON 13

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
	void		*mlx;
	void		*win;
	int			mov;
	t_map		map;
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

/*
╔════════════════════╗
		MAIN
╚════════════════════╝
*/

/*
╔════════════════════╗
			MAPS
╚════════════════════╝
*/

void			ft_map_existence(char **argv, t_map *map);
void			ft_create_map(t_map *map, int fd);
void			ft_is_closemap(t_map *map);
void			ft_map_components(t_map *map);
void			ft_is_valid(t_map *map, t_vector2d cor);

/*
╔════════════════════╗
		MAPS UTILS
╚════════════════════╝
*/

int				ft_check_horizontal_map(t_map *map);
int				ft_check_vertical_map(t_map *map);
void			ft_check_rectangularmap(t_map *map);
int				*ft_check_components(char pos, int *keeper);

/*
╔════════════════════╗
		MAPS UTILS2
╚════════════════════╝
*/

void			floodfill(t_map *checkmap, t_vector2d cor);
int				ft_slpath_exist(t_map *checkmap, t_vector2d cor);
char			**ft_matrizdup(const char **matriz);
int				*ft_find_component(t_map *map, char c);
/*
╔════════════════════╗
		CALLBACK
╚════════════════════╝
*/
int				ft_event_listener(int keycode, t_mlx *mlx);
int				ft_sprite_dir(int keycode, t_mlx *mlx);

/*
╔════════════════════╗
		MOVEMENTS
╚════════════════════╝
*/
int				ft_player_down(t_map *map);
int				ft_player_up(t_map *map);
int				ft_player_right(t_map *map);
int				ft_player_left(t_map *map);

/*
╔════════════════════╗
		ERROR
╚════════════════════╝
*/
void			ft_map_error(t_map *map, char *message);
void			ft_sl_error(char *message);
void			ft_free_array(char **matriz);

/*
╔════════════════════╗
		Image
╚════════════════════╝
*/

void			ft_render_daddy(t_mlx *mlx, int	play_dir);
void			ft_construct_image(t_mlx *mlx, t_sprites *spr);

#endif
