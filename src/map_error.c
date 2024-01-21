/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:03:36 by deordone          #+#    #+#             */
/*   Updated: 2024/01/21 13:31:19 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_error(t_map *map, char *message)
{
	ft_free_array(map->map);
	ft_dprintf(2, message);
	exit(1);
}

void	ft_sl_error(char *message)
{
	ft_dprintf(2, message);
	exit(1);
}

void	ft_free_array(char **res)
{
	int	i;

	i = 0;
	if (res)
	{
		while (res[i])
			i++;
		while (--i)
			free(res[i]);
		free(res[i]);
		free(res);
	}
}
