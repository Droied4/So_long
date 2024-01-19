/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:45:40 by deordone          #+#    #+#             */
/*   Updated: 2024/01/19 13:56:57 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//is_validmap
//map_components
//is_closemap
//is_rectangularmap
//get_map 

void get_map(char **argv)
{
	t_map map;
	char *line;
	char *final_line;
//comprobar si argv1 existe y termina con .ber antes de esto
	map.fd_map = open(argv[1], O_RDONLY);
	if (!map.fd_map)
		return (mensaje error no mapa*/);
	line = get_next_line(map.fd_map);
	if (!line)
		return (mensaje error no hay nada */)
	while (line)
	{
		map.height_map = map.height_map++;
		map.width_map = ft_strlen(line);
		//crear funcion que compare el ancho con el anterior si es igual no pasa nada si es mayor o menor acaba con todo. isrectangularmap puede ser
		final_line = ft_strjoin(final_line, line);
		line = get_next_line(map.fd_map);
	}
	if (final_line)
		hago un split*/
	else
		return (mensaje error no hay nada */)

//dos get next line uno que me cuente cuantos caracteres hay y otro que me guarde en una matriz los caracteres del mapa	
}
