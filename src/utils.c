/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:26:34 by carmeno           #+#    #+#             */
/*   Updated: 2024/01/14 21:27:08 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long"

void    my_pixel_put(t_img *data, int x, int y, int color)
{
        char    *dst;

        dst = data->addr + (y * data->l_line + x * (data->bpp / 8));
        *(unsigned int *)dst = color;
}
