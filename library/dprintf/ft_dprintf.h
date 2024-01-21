/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:09:28 by deordone          #+#    #+#             */
/*   Updated: 2024/01/14 22:21:23 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_dprintf(int fd, const char *str, ...);
int		ft_dputchar(int fd, int c);
int		ft_dputstr(int fd, const char *str);
int		ft_dputnbr(int fd, int nb);
int		ft_dputunsnbr(int fd, unsigned int nb);
int		ft_dputhxanbr(int fd, unsigned int n);
int		ft_dputhxanbr_up(int fd, unsigned int n);
int		ft_dputhxaptr(int fd, unsigned long n);

#endif
