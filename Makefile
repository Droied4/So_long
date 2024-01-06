# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carmeno <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 22:34:39 by carmeno           #+#    #+#              #
#    Updated: 2024/01/06 23:16:55 by carmeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #  
#                               SO_LONG                                        #
# **************************************************************************** #  
NAME        = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_PATH)

# **************************************************************************** #  
#                               SOURCES                                        #
# **************************************************************************** #  

SOURCES_PATH    = ./src
OBJECTS_PATH    = ./obj
INCLUDE_PATH    = ./include
LIBRARY_PATH	= ./library
LIBFT_PATH	= $(LIBRARY_PATH)/libft
PRINTF_PATH	= $(LIBRARY_PATH)/printf
MINILIBX_PATH    = $(LIBRARY_PATH)/minilibx

LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a
MINILIBX = $(MINILIBX_PATH)/libmlx.a

HEADER = $(INCLUDE_PATH)/so_long.h
SOURCES = so_long.c

# **************************************************************************** #  
#                               OBJECTS                                        #
# **************************************************************************** #  

OBJECTS = $(addprefix obj/, ${SOURCES:.c=.o})
DEPS = $(SRC:.c=.d)

# **************************************************************************** #  
#                               COLORS                                         #
# **************************************************************************** #  

RED=\033[0;31m
CYAN=\033[0;36m
GREEN=\033[0;32m
YELLOW=\033[0;33m
WHITE=\033[0;97m
BLUE=\033[0;34m
NC=\033[0m # No color

# **************************************************************************** #  
#                               RULES                                          #
# **************************************************************************** #  

all: header $(NAME)

-include $(DEPS)
$(NAME):  $(OBJECTS) $(LIBFT) $(MINILIBX) 
		@printf "$(GREEN)";  
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) 

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER) Makefile
		@printf "$(GREEN)";  
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_PATH)

$(MINILIBX) :
	make -C $(MINILIBX_PATH)

clean: ok
	rm -rf obj 
	rm -f $(DEPS)

fclean : ok clean
		rm -rf $(NAME)

re: fclean all 

header: 
	@echo
	@printf "$(RED)		  ══════════════════════════「₪」══════════════════════════\n";
	@echo
	@printf "     	          $(YELLOW)                      ▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n";
	@printf "	     	                      ▒▒▒▒▒▒▒▒▒     ▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒\n";
	@printf "	     	                    ▒▒▒▒▒▒▒▒▒       ▒▒▒▒     ▒▒▒▒▒▒▒\n";
	@printf "	     	                  ▒▒▒▒▒▒▒▒▒         ▒▒      ▒▒▒▒▒▒▒\n";
	@printf "	     	                ▒▒▒▒▒▒▒▒▒                  ▒▒▒▒▒▒▒▒\n";
	@printf "	     	              ▒▒▒▒▒▒▒▒▒                  ▒▒▒▒▒▒▒▒\n";
	@printf "	     	            ▒▒▒▒▒▒▒▒                  ▒▒▒▒▒▒▒▒\n";
	@printf "	     	          ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒     ▒▒▒▒▒▒▒▒     ▒▒\n";
	@printf "	     	          ▒▒▒▒▒▒ Droied$(YELLOW) ▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒    ▒▒▒▒\n";
	@printf "	     	          ▒▒▒▒▒▒▒ Pacman ▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒\n";
	@printf "	     	          ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   ▒▒ Barcelona ▒▒▒\n";
	@printf "	     	          ░░░░░ $(BLUE)  ░░░░░ $(YELLOW) ▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n";
	@printf "	     	         ░░░░$(WHITE)▀$(YELLOW)░░$(BLUE) ░$(WHITE)▄ $(BLUE)░$(WHITE)▄ $(BLUE)░ $(YELLOW)▒▒▒▒▒▒▒▒      |\n";
	@printf "	    	         ░░░░░  $(BLUE) ░░░░░░░$(YELLOW) ▒▒▒▒▒▒▒▒      ╰┈➤Pipex \n";
	@printf "	     	          ░░░░░ $(BLUE) ░ ░ ░ ░$(YELLOW) ▒▒▒▒▒▒▒▒$(NC)\n";
	@echo
	@printf "$(RED)		  ══════════════════════════「₪」══════════════════════════$(GREEN)\n";
	@echo
 
help: 
	@printf "\n";  
	@printf "	▂▃▅▆█▆▅▃▂ Commands ▂▃▅▆█▆▅▃▂\n";
	@printf "$(BLUE)		  ► help \n";
	@printf "		  ► clean \n";
	@printf "		  ► fclean \n";
	@printf "		  ► re \n";
	@printf "		  ► author $(NC)  \n";
	@printf "\n"; 
#	@tput setaf 009; echo "		  ► bonus "

author: 
	@printf "\n";
	@printf "$(CYAN)		       	       Created by Droied - Ataraxia\n";
	@printf "$(RED)		  ══════════════════════════「₪」══════════════════════════\n";
	@printf "$(CYAN)		        	https://github.com/Droied4 \n";
	@printf "\n";

compiled_libft: 
	@echo
	@printf "$(RED)		  ══════════════════════════「LIBFT ₪ COMPILED」══════════════════════════\n";
	@echo

ok:
	@printf "\n"; 
	@printf "$(RED)Ok";
	@printf "\n"; 

.PHONY: all clean fclean re
