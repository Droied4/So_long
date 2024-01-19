/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:46:27 by deordone          #+#    #+#             */
/*   Updated: 2024/01/19 12:46:30 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*inicializo los valores de mis colores predefinidos*/

void    ft_init_colors(t_colors *color)
{
        color->red = 0x00FF0000;
        color->green = 0x0000FF00;
        color->blue = 0x000000FF;
        color->black = 0x00000000;
        color->white = 0x00FFFFFF;
        color->yellow = 0x00FFFF00;
        color->magenta = 0x00FF00FF;
        color->cyan = 0x00FFFF00;
        color->brown = 0x00A52A2A;
        color->orange = 0x00FFA500;
        color->purple = 0x008A2BE2;
}

/*funcion que invierta los colores*/

/*funcion que modique la transparencia de un color*/
