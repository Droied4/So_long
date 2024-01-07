/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:46:12 by carmeno           #+#    #+#             */
/*   Updated: 2024/01/07 02:30:03 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (void)
{
	void	*mlx;
	void	*mlx_win;
	
	ft_putstr_fd("libft ok\n", 1);
	ft_printf("printf %s\n","ok");

	mlx = mlx_init();
	if (!mlx)
		exit(1);
	mlx_win = mlx_new_window(mlx, 300, 300, "santito");
	if (!mlx_win)
		exit(1);
	mlx_loop(mlx);
	return (0);
}
