/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:46:45 by carmeno           #+#    #+#             */
/*   Updated: 2024/09/24 20:10:04 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../library/ft_dprintf/ft_dprintf.h"
# include "../library/get_next_line/get_next_line.h"
# include "../library/libft/libft.h"
# include "../library/MLX42/include/MLX42/MLX42.h"
# include "../library/printf/ft_printf.h"
# include "sl_macro.h"
# include "sl_struct.h"

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

void	ft_map_existence(char **argv, t_map *map);
void	ft_create_map(t_map *map, int fd);
void	ft_is_closemap(t_map *map);
void	ft_map_components(t_map *map);
void	ft_is_valid(t_map *map, t_vector2d cor);

/*
╔════════════════════╗
		MAPS UTILS
╚════════════════════╝
*/

void	ft_win_size(t_mlx *mlx);
int		ft_check_horizontal_map(t_map *map);
int		ft_check_vertical_map(t_map *map);
void	ft_check_rectangularmap(t_map *map);
int		*ft_check_components(char pos, int *keeper);

/*
╔════════════════════╗
		MAPS UTILS2
╚════════════════════╝
*/

void	ft_too_large(t_map *map);
void	floodfill(t_map *checkmap, t_vector2d cor);
int		ft_slpath_exist(t_map *checkmap, t_vector2d cor);
char	**ft_matrizdup(const char **matriz);
int		*ft_find_component(t_map *map, char c);
/*
╔════════════════════╗
		CALLBACK
╚════════════════════╝
*/
int		ft_destroy_window(t_mlx *mlx);
int		ft_event_listener(t_mlx *mlx);
int		ft_sprite_dir(t_mlx *mlx);

/*
╔════════════════════╗
		MOVEMENTS
╚════════════════════╝
*/
int		ft_player_down(t_map *map, t_mlx *mlx);
int		ft_player_up(t_map *map, t_mlx *mlx);
int		ft_player_right(t_map *map, t_mlx *mlx);
int		ft_player_left(t_map *map, t_mlx *mlx);

/*
╔════════════════════╗
		ERROR
╚════════════════════╝
*/
char	*ft_sl_strjoin(char const *s1, char const *s2);
void	ft_map_error(t_map *map, char *message);
void	ft_sl_error(char *message);
void	ft_free_array(char ***matriz);

/*
╔════════════════════╗
		Image
╚════════════════════╝
*/

void	ft_render_daddy(t_mlx *mlx, int play_dir);
void	ft_construct_image(t_mlx *mlx, t_sprites *spr);

#endif
