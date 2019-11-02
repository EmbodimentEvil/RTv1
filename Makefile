# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 17:13:33 by sleonia           #+#    #+#              #
#    Updated: 2019/11/02 23:36:11 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

#****************************************************************************#
#					SETTINGS FOR CONCLUSION IN CONSOLE 						 #
#****************************************************************************#

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
AQUA = \033[36m
GREY = \033[37m
UNDERLINE = \033[4m
NORMAL = \033[0m

#****************************************************************************#
#									COLORS 									 #
#****************************************************************************#

NAME = RT

FRAMEDIR = /Users/$(USER)/Library/Frameworks

SRC_PATH = ./source/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
LIB_PATH = ./includes/libft
INC =   -I $(INC_PATH) -I $(LIB_PATH) -I ./ \
        -I $(FRAMEDIR)/SDL2.framework/Versions/A/Headers \
        -I $(FRAMEDIR)/SDL2_image.framework/Versions/A/Headers \
        -I $(FRAMEDIR)/SDL2_ttf.framework/Versions/A/Headers \
        -I $(FRAMEDIR)/SDL2_mixer.framework/Versions/A/Headers

FRAME = $(FRAMEDIR)/SDL2.framework $(FRAMEDIR)/SDL2_image.framework \
        $(FRAMEDIR)/SDL2_mixer.framework $(FRAMEDIR)/SDL2_ttf.framework

FLAGS = 	-Ofast -c -g

FLAGS2 =    -F ~/Library/Frameworks/ -framework SDL2 -framework SDL2_image \
            -framework SDL2_ttf -framework SDL2_mixer

LIB = 		-L$(LIB_PATH) -lft

SRC_NAME =	main.c			\
			init.c 			\
			rgb.c			\
			validation.c	\
			sdl.c			\

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(FRAMEDIR) $(FRAME) $(NAME)

$(NAME): $(OBJ)
	@Make -C $(LIB_PATH)
	@gcc $(OBJ) $(INC) $(LIB) $(FLAGS2) -o $(NAME)
	@echo ""
	@echo "\n\t\t        $(BLUE)💥 RT READY!💥\t\t     "
	@echo "💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀\
💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) $(INC) $< -o $@

$(FRAMEDIR):
		@mkdir -p $(FRAMEDIR)
		@rm -rf $(FRAMEDIR)/*

$(FRAME): $(FRAMEDIR)/%: Frameworks/%
		@cp -R $< $(FRAMEDIR)
clean:
	@clear
	@Make -C $(LIB_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@Make -C $(LIB_PATH) fclean
	@rm -f $(NAME)

re: fclean all
