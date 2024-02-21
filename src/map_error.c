/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:03:36 by deordone          #+#    #+#             */
/*   Updated: 2024/02/21 10:31:15 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_error(t_map *map, char *message)
{
//	if (map->map)
	ft_free_array(&map->map);
	ft_dprintf(2, message);
	exit(1);
}

void	ft_sl_error(char *message)
{
	ft_dprintf(2, message);
	exit(1);
}

void	ft_free_array(char ***res)
{
	int	i;

	i = 0;
	if (*res)
	{
		while ((*res)[i])
			i++;
		while (--i)
			free((*res)[i]);
		free((*res)[i]);
		free(*res);
	}
}

char	*ft_sl_strjoin(char const *s1, char const *s2)
{
	char	*rsv;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	rsv = malloc ((sizeof(char)) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rsv)
		return (NULL);
	while (s1[i])
	{
		rsv[i] = s1[i];
		i++;
	}
	while (s2[i2])
	{
		rsv[i] = s2[i2];
		i++;
		i2++;
	}
	rsv[i] = '\0';
	free((void *)s1);
	free((void *)s2);
	return ((char *) rsv);
}
