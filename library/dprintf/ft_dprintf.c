/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 07:55:42 by deordone          #+#    #+#             */
/*   Updated: 2024/01/16 12:12:06 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	dprint_special(int fd, char spec, va_list argptr)
{
	int	aux;

	aux = 0;
	if (spec == 'c')
		aux += ft_dputchar(fd, va_arg(argptr, int));
	else if (spec == 's')
		aux += ft_dputstr(fd, va_arg(argptr, const char *));
	else if (spec == 'd' || spec == 'i')
		aux += ft_dputnbr(fd, va_arg(argptr, int));
	else if (spec == 'u')
		aux += ft_dputunsnbr(fd, va_arg(argptr, unsigned int));
	else if (spec == 'x')
		aux += ft_dputhxanbr(fd, va_arg(argptr, unsigned int));
	else if (spec == 'X')
		aux += ft_dputhxanbr_up(fd, va_arg(argptr, unsigned int));
	else if (spec == 'p')
	{
		if (write(fd, "0x", 2) == -1)
			return (-1);
		aux = ft_dputhxaptr(fd, va_arg(argptr, unsigned long));
		aux += 2;
	}
	else
		return (write(fd, &spec, 1));
	return (aux);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	int		aux;
	int		i;
	va_list	argptr;

	va_start(argptr, str);
	i = 0;
	aux = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\\')
		{
			i++;
			aux += dprint_special(fd, str[i], argptr);
		}
		else
		{
			aux += write(fd, &str[i], 1);
		}
		if (aux < 0)
			return (-1);
		i++;
	}
	va_end(argptr);
	return (aux);
}
/*
int	main(void)
{
	int		rslt;

	rslt = ft_printf("%p", (void *)14523);
	printf ("\n%d", rslt);
	return (0);
}*/
