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

NAME = gnl_test
PATH_SRC = ./
PATH_HEADERS = -I includes/ -I ../includes/ -I ../../rlists/includes/
SRC = $(PATH_SRC)main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CLIBS_PATH =	-L ../ \
		-L ../../rlists/

CLIBS =		-l ft \
		-l rlists
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../
	$(CC) $(CFLAGS) $(CLIBS_PATH) -o $(NAME) $(OBJ) $(CLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(PATH_HEADERS) -o $@ -c $<

nolib: $(NAME)
	$(CC) $(CFLAGS) $(CLIBS_PATH) -o $(NAME) $(OBJ) $(CLIBS)

clean:
	@rm -f $(OBJ)
	make -C ../ clean
	@echo removed binary files

fclean: clean
	@rm -f $(NAME)
	make -C ../ fclean
	@echo removed library

re: fclean all

.PHONY: all clean fclean re nolib
