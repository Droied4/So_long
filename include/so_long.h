/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:46:45 by carmeno           #+#    #+#             */
/*   Updated: 2024/01/08 03:30:37 by carmeno          ###   ########.fr       */
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

typedef struct s_color
{
	int		red;
	int		blue;
	int		yellow;
	int		cyan;
	int		brown;
	int		magenta;
	int		orange;
	int		green;
	int		black;
	int		white;
}			t_color;

#endif
