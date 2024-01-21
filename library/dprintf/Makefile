# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deordone <deordone@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 12:12:27 by deordone          #+#    #+#              #
#    Updated: 2024/01/14 22:20:32 by carmeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = \
	ft_dprintf.c ft_dputchar.c ft_dputstr.c ft_dputnbr.c ft_dputunsnbr.c \
	ft_dputhxanbr.c ft_dputhxanbr_up.c ft_dputhxaptr.c

HEADER = ft_dprintf.h
INCLUDE = -I

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) Makefile
	$(AR) $(NAME) $(OBJECTS) 

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCLUDE)/$(HEADER) -c $<

clean: Makefile
	rm -f $(OBJECTS)

fclean: clean Makefile
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
