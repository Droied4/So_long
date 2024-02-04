/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:46:16 by deordone          #+#    #+#             */
/*   Updated: 2024/02/04 16:47:02 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    my_pixel_put(t_img *data, int x, int y, int color)
{
        char    *dst;

        dst = data->addr + (y * data->l_line + x * (data->bpp / 8));
        *(unsigned int *)dst = color;
}
