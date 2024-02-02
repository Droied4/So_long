/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:46:45 by carmeno           #+#    #+#             */
/*   Updated: 2024/02/02 17:26:15 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../library/ft_dprintf/ft_dprintf.h"
# include "../library/get_next_line/get_next_line.h"
# include "../library/libft/libft.h"
# include "../library/minilibx_mac/mlx.h"
# include "../library/printf/ft_printf.h"

# define SPACE '0'
# define SPACE_PATH "./sprites/space.xpm"
# define WALL '1'
# define WALL_PATH "./sprites/wall.xpm"
# define ITEM 'C'
# define ITEM_PATH "./sprites/item.xpm"
# define EXIT 'E'
# define EXIT_PATH "./sprites/exit.xpm"
# define PLAYER 'P'
# define PLAYER_PATH "./sprites/player.xpm"
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
	t_vector2d	player;
}				t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
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
void			ft_init_map(t_map *map);
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
		MOVEMENTS
╚════════════════════╝
*/
int	ft_event_listener(int keycode, t_mlx *mlx);
/*
╔════════════════════╗
		ERROR
╚════════════════════╝
*/
void			ft_map_error(t_map *map, char *message);
void			ft_sl_error(char *message);
void			ft_free_array(char **matriz);


/*
 *	SHAPES
 *
 * */

void			draw_triangle(t_img);
void			draw_cube(t_img);
void			draw_circle(t_img img, int center_x, int center_y, int radius);

/*
 *
 *	ALGORITMOS
 *
 * */

void			dda_line(t_img img, t_vector2d p1, t_vector2d p2);

/*
 *
 * UTILS
 *
 * */

void			my_pixel_put(t_img *data, int x, int y, int color);

#endif
