/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:46:45 by carmeno           #+#    #+#             */
/*   Updated: 2024/01/08 04:41:51 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../library/libft/libft.h"
# include "../library/minilibx/mlx.h"
# include "../library/printf/ft_printf.h"

/*Datos para las imagenes*/
typedef struct s_data_img
{
	void		*img;
	char		*addr;
	int		bpp;
	int		l_line;
	int		endian;
}			t_data_img;

typedef struct s_colors
{
	int		red;
	int		green;
	int		blue;
	int		black;
	int		white;
	int		yellow;
	int		magenta;
	int		cyan;
	int		brown;
	int		orange;
	int		purple;
}			t_colors;

#endif
