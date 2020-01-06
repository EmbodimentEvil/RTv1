# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 17:13:33 by sleonia           #+#    #+#              #
#    Updated: 2020/01/06 15:14:57 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
AQUA = \033[36m
GREY = \033[37m
UNDERLINE = \033[4m
NORMAL = \033[0m

NAME = RT

FRAMEDIR = /Users/$(USER)/Library/Frameworks

SRC_PATH = ./source/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
LIB_PATH = ./libft
INC = -I .  -I $(INC_PATH) -I $(LIB_PATH) -I ./ \
    		-I src/ \
			-I Frameworks/SDL2.framework/Versions/A/Headers \
			-I Frameworks/SDL2/SDL2_image.framework/Versions/A/Header \
			-I Frameworks/SDL2/SDL2_ttf.framework/Versions/A/Header \
			-I Frameworks/SDL2/SDL2_mixer.framework/Versions/A/Header \
			-F Frameworks/

FRAME = 	-F Frameworks/ -framework SDL2 -framework SDL2_image \
            -framework SDL2_ttf -framework SDL2_mixer -rpath Frameworks/

FLAGS = 	-Ofast -c -g
# FLAGS = 	-Ofast -c -g -Wall -Werror -Wextra


LIB = 		-L$(LIB_PATH) -lft

SRC_NAME =	calculate_normals.c			\
			color_parse.c				\
			draw.c						\
			find.c						\
			help.c						\
			hit.c						\
			init.c						\
			light.c						\
			main.c						\
			sdl_loop.c					\
			validation.c				\
			validation_get_value.c		\
			validation_light.c			\
			validation_objects.c		\

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@Make -C $(LIB_PATH)
	@gcc $(OBJ) $(INC) $(LIB) $(FRAME) -o $(NAME)
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

# $(FRAME): $(FRAMEDIR)/%: Frameworks/%
# 		@cp -R $< $(FRAMEDIR)
clean:
	@clear
	@Make -C $(LIB_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@Make -C $(LIB_PATH) fclean
	@rm -f $(NAME)

re: fclean all
