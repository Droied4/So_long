# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carmeno <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 22:34:39 by carmeno           #+#    #+#              #
#    Updated: 2024/09/24 19:31:07 by droied           ###   ########.fr        #
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
	MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit
endif
ifeq ($(OS), Linux)
	MLXFLAGS = -ldl -lglfw -lm
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
MLX_PATH = $(LIBRARY_PATH)/MLX42

LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a
DPRINTF = $(DPRINTF_PATH)/libftdprintf.a
GNLINE = $(GNLINE_PATH)/get_next_line.a
MLX = $(MLX_PATH)/libmlx42.a

HEADER += $(INCLUDE_PATH)/so_long.h
HEADER += $(INCLUDE_PATH)/sl_struct.h
HEADER += $(INCLUDE_PATH)/sl_macro.h
SOURCES = so_long.c maps.c maps_utils.c maps_utils2.c map_error.c movement.c callback.c image.c

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

-include $(DEPS)
$(NAME): $(OBJECTS) $(LIBFT) $(PRINTF) $(DPRINTF) $(GNLINE)
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

# $(MLX_PATH)/Makefile:
	# @$(call compile,cmake -B $(MLX_PATH) $(MLX_PATH))

# $(MLX): $(MLX_PATH)/Makefile
	# @$(call compile,make -C $(MLX_PATH))

clean:
	@printf "$(CYAN)Cleaning objects and libraries$(NC)\n";
	@rm -rf $(OBJECTS_PATH) 
	@make clean -C $(LIBFT_PATH) > /dev/null
	@make clean -C $(PRINTF_PATH) > /dev/null
	@make clean -C $(DPRINTF_PATH) > /dev/null

fclean : clean
	@printf "$(CYAN)Cleaning objects, libraries and executable$(NC)\n";
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH) > /dev/null
	@make fclean -C $(PRINTF_PATH) > /dev/null
	@make fclean -C $(DPRINTF_PATH) > /dev/null

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
