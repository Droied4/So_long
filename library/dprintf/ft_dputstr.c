/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 07:55:37 by deordone          #+#    #+#             */
/*   Updated: 2024/01/14 22:25:45 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dputstr(int fd, const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_dputstr(fd, "(null)"));
	while (str[i])
	{
		if (write(fd, &str[i], 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}
