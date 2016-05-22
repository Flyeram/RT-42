# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/18 21:30:01 by bkabbas           #+#    #+#              #
#    Updated: 2016/03/23 15:56:44 by bkabbas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = raytracer
PATH_SRC = src/

PATH_RLISTS = libs/rlists
PATH_FT = libs/libft
PATH_RMATH = libs/rmath
PATH_MLX = libs/minilibx

OPTIMIZE = yes
DEBUG = no

PATH_HEADERS = -I includes/ \
			   -I $(PATH_FT)/includes/ \
			   -I $(PATH_R3D)/includes/ \
			   -I $(PATH_RLISTS)/includes/ \
			   -I $(PATH_RMATH)/includes/ \
			   -I $(PATH_MLX)/includes/

SRC = $(PATH_SRC)main.c $(PATH_SRC)texture.c $(PATH_SRC)raytracer.c $(PATH_SRC)intersects.c $(PATH_SRC)camera.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifeq ($(OPTIMIZE), yes)
	CFLAGS += -O3
endif

ifeq ($(DEBUG), yes)
	CFLAGS += -O0 -g
endif

CLIBS_PATH =	-L $(PATH_RLISTS)/ \
				-L $(PATH_RMATH)/ \
				-L $(PATH_FT)/ \
				-L $(PATH_MLX)/

CLIBS =	-l ft \
		-l rlists \
		-l rmath \
		-l mlx \
		-l m \
		-lXext \
		-lX11

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(PATH_FT)/
	make -C $(PATH_RLISTS)/
	make -C $(PATH_RMATH)/
	make -C $(PATH_MLX)/
	$(CC) $(CFLAGS) $(CLIBS_PATH) -o $(NAME) $(OBJ) $(CLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(PATH_HEADERS) -o $@ -c $<

nolib: $(NAME)
	$(CC) $(CFLAGS) $(CLIBS_PATH) -o $(NAME) $(OBJ) $(CLIBS)

clean:
	@rm -f $(OBJ)
	make -C $(PATH_FT)/ clean
	make -C $(PATH_RLISTS)/ clean
	make -C $(PATH_RMATH)/ clean
	make -C $(PATH_MLX)/ clean
	@echo removed binary files

fclean: clean
	@rm -f $(NAME)
	make -C $(PATH_FT)/ fclean
	make -C $(PATH_RLISTS)/ fclean
	make -C $(PATH_RMATH)/ fclean
	make -C $(PATH_MLX)/ clean
	@echo removed library

re: fclean all

.PHONY: all clean fclean re nolib
