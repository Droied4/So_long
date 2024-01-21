/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputunsnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:31:42 by deordone          #+#    #+#             */
/*   Updated: 2024/01/14 22:26:25 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dputunsnbr(int fd, unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_dputunsnbr(fd, nb / 10);
		if (count == -1)
			return (-1);
	}
	if (ft_dputchar(fd, (nb % 10) + '0') == -1)
		return (-1);
	count++;
	return (count);
}
