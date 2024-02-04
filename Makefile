# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carmeno <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 22:34:39 by carmeno           #+#    #+#              #
#    Updated: 2024/02/04 16:28:13 by deordone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ╔══════════════════════════════════════════════════════════════════════════╗ #  
#                               SO_LONG                                        #
# ╚══════════════════════════════════════════════════════════════════════════╝ #  
NAME        = so_long
OS = $(shell uname)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_PATH) -MMD -MF $(@:.o=.d) -g

ifeq ($(OS), Darwin)
	MLXFLAGS = -framework OpenGL -framework AppKit -lm
endif
ifeq ($(OS), Linux)
	MLXFLAGS = -lX11 -lXext -lm 
endif

# ╔══════════════════════════════════════════════════════════════════════════╗ #  
#                               SOURCES                                        #
# ╚══════════════════════════════════════════════════════════════════════════╝ #  

SOURCES_PATH    = ./src
OBJECTS_PATH    = ./obj
INCLUDE_PATH    = ./include
LIBRARY_PATH	= ./library
LIBFT_PATH	= $(LIBRARY_PATH)/libft
PRINTF_PATH	= $(LIBRARY_PATH)/printf
DPRINTF_PATH	= $(LIBRARY_PATH)/ft_dprintf
GNLINE_PATH	= $(LIBRARY_PATH)/get_next_line
LINUX_MINILIBX_PATH    = $(LIBRARY_PATH)/minilibx_linux
MAC_MINILIBX_PATH = $(LIBRARY_PATH)/minilibx_mac

LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a
DPRINTF = $(DPRINTF_PATH)/libftdprintf.a
GNLINE = $(GNLINE_PATH)/get_next_line.a
MINILIBX_MAC = $(MAC_MINILIBX_PATH)/libmlx.a
MINILIBX_LINUX = $(LINUX_MINILIBX_PATH)/libmlx_Linux.a

HEADER = $(INCLUDE_PATH)/so_long.h
SOURCES = so_long.c maps.c maps_utils.c maps_utils2.c map_error.c movement.c callback.c

# ╔══════════════════════════════════════════════════════════════════════════╗ #  
#                               OBJECTS                                        #
# ╚══════════════════════════════════════════════════════════════════════════╝ #  

OBJECTS = $(addprefix $(OBJECTS_PATH)/, ${SOURCES:.c=.o})
DEPS = $(addprefix $(OBJECTS_PATH)/, ${SOURCES:.c=.d})

# ╔══════════════════════════════════════════════════════════════════════════╗ #  
#                               COLORS                                         #
# ╚══════════════════════════════════════════════════════════════════════════╝ #  

RED=\033[0;31m
CYAN=\033[0;36m
GREEN=\033[0;32m
YELLOW=\033[0;33m
WHITE=\033[0;97m
BLUE=\033[0;34m
NC=\033[0m # No color

# ╔══════════════════════════════════════════════════════════════════════════╗ #  
#                               RULES                                          #
# ╚══════════════════════════════════════════════════════════════════════════╝ #  

all: header make_libs $(NAME)

make_libs:
	@make -C $(LIBFT_PATH) > /dev/null
#	@printf "$(CYAN)Compiling $(LIBFT_PATH)$(NC)\n";
	@make -C $(PRINTF_PATH) > /dev/null
#	@printf "$(CYAN)Compiling $(PRINTF_PATH)$(NC)\n";
	@make -C $(DPRINTF_PATH) > /dev/null
#	@printf "$(CYAN)Compiling $(DPRINTF_PATH)$(NC)\n";
	@make -C $(GNLINE_PATH) > /dev/null
#	@printf "$(CYAN)Compiling $(GNLINE_PATH)$(NC)\n";
	@make -C $(MAC_MINILIBX_PATH) > /dev/null 2>&1
#	@printf "$(CYAN)Compiling $(MAC_MINILIBX_PATH)$(NC)\n";

-include $(DEPS)
$(NAME): $(OBJECTS) $(LIBFT) $(PRINTF) $(DPRINTF) $(GNLINE) $(MINILIBX_MAC)  #$(MINILIBX_LINUX) 
	@printf "$(CYAN)$@ Compiled$(NC)\n";
	@$(CC) $(CFLAGS) $^ -o $(NAME) $(MLXFLAGS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER) Makefile
		@printf "$(CYAN)Compiling $@$(NC)\n";
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@ 

$(LIBFT) :
	@printf "$(CYAN)Compiling $@$(NC)\n";
	@make -C $(LIBFT_PATH) > /dev/null

$(PRINTF) :
	@printf "$(CYAN)Compiling $@$(NC)\n";
	@make -C $(PRINTF_PATH) > /dev/null

$(DPRINTF) :
	@printf "$(CYAN)Compiling $@$(NC)\n";
	@make -C $(DPRINTF_PATH) > /dev/null

$(GNLINE) :
	@printf "$(CYAN)Compiling $@$(NC)\n";
	@make -C $(GNLINE_PATH) > /dev/null

$(MINILIBX_MAC) :
	@printf "$(CYAN)Compiling $@$(NC)\n";
	@make -C $(MAC_MINILIBX_PATH) > /dev/null 2>&1 

$(MINILIBX_LINUX) :
	@printf "$(CYAN)Compiling $@$(NC)\n";
	@make -C $(LINUX_MINILIBX_PATH) > /dev/null 2>&1

clean:
	@printf "$(CYAN)Cleaning objects and libraries$(NC)\n";
	@rm -rf $(OBJECTS_PATH) 
	@make clean -C $(LIBFT_PATH) > /dev/null
	@make clean -C $(PRINTF_PATH) > /dev/null
	@make clean -C $(DPRINTF_PATH) > /dev/null
	@make clean -C $(GNLINE_PATH) > /dev/null
#	@make clean -C $(LINUX_MINILIBX_PATH)> /dev/null 2>&1
	@make clean -C $(MAC_MINILIBX_PATH) > /dev/null 2>&1

fclean : clean
	@printf "$(CYAN)Cleaning objects, libraries and executable$(NC)\n";
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH) > /dev/null
	@make fclean -C $(PRINTF_PATH) > /dev/null
	@make fclean -C $(DPRINTF_PATH) > /dev/null
	@make fclean -C $(GNLINE_PATH) > /dev/null
#	@make clean -C $(LINUX_MINILIBX_PATH)> /dev/null 2>&1
	@make clean -C $(MAC_MINILIBX_PATH) > /dev/null 2>&1

re: fclean all 

header: 
	@echo
	@printf "$(RED)		  ══════════════════════════$(WHITE)「₪」$(RED)══════════════════════════$(GREEN)\n";
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
	@printf "	    	         ░░░░░  $(BLUE) ░░░░░░░$(YELLOW) ▒▒▒▒▒▒▒▒      ╰┈➤$(NAME) \n";
	@printf "	     	          ░░░░░ $(BLUE) ░ ░ ░ ░$(YELLOW) ▒▒▒▒▒▒▒▒$(NC)\n";
	@echo
	@printf "\n $(RED)	   ╔══════════════════════════════════════════════════════════════════════════╗$(NC)\n"
	@printf "$(WHITE)      	       • • ᗣ • • • • • • • • ᗧ • • ᗣ • • • • • • • • • • ᗣ • • • • • • • •$(NC)\n"
	@printf "  $(RED)	   ╚══════════════════════════════════════════════════════════════════════════╝$(NC)\n"
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
	@printf "$(CYAN)	 	         	Created by 𝗗𝗿𝗼𝗶e𝗱 -大卫\n";
	@printf "$(RED)		  ══════════════════════════「₪」══════════════════════════\n";
	@printf "$(CYAN)		        	https://github.com/Droied4 \n";
	@printf "\n";

.PHONY: all clean fclean re
