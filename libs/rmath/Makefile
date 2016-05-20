# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/18 21:24:52 by bkabbas           #+#    #+#              #
#    Updated: 2016/01/18 23:32:51 by bkabbas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = librmath.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIMIZE = yes
PROF = no
DEBUG = no

# Paths
PATH_HEADERS = -I includes/
PATH_SRC = src/
PATH_M4F = $(PATH_SRC)m4f/
PATH_V4F = $(PATH_SRC)v4f/
PATH_V3F = $(PATH_SRC)v3f/
PATH_V2F = $(PATH_SRC)v2f/

# Debug
ifeq ($(DEBUG), yes)
	CFLAGS += -g -O0
endif

# Prof
ifeq ($(PROF), yes)
	CFLAGS += -pg
endif

# Optimization
ifeq ($(OPTIMIZE), yes)
	CFLAGS += -O3
endif

# Sources
M4F = $(PATH_M4F)m4f_manipulations.c \
      $(PATH_M4F)m4f_operators.c \
      $(PATH_M4F)m4f_adjugate.c \
      $(PATH_M4F)m4f_initializers.c

V4F = $(PATH_V4F)v4f_manipulations.c \
      $(PATH_V4F)v4f_operators.c \
      $(PATH_V4F)v4f_operators_new.c \
      $(PATH_V4F)v4f_operators_float.c \
      $(PATH_V4F)v4f_utils.c

V3F = $(PATH_V3F)v3f_manipulations.c \
      $(PATH_V3F)v3f_operators.c \
      $(PATH_V3F)v3f_operators_new.c \
      $(PATH_V3F)v3f_operators_float.c \
      $(PATH_V3F)v3f_utils.c

V2F = $(PATH_V2F)v2f_manipulations.c \
      $(PATH_V2F)v2f_operators.c \
      $(PATH_V2F)v2f_operators_new.c \
      $(PATH_V2F)v2f_operators_float.c \
      $(PATH_V2F)v2f_utils.c

SOURCES = $(M4F)
SOURCES += $(V4F)
SOURCES += $(V3F)
SOURCES += $(V2F)

# Objects
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo library linked correctly

%.o: %.c
	$(CC) $(CFLAGS) $(PATH_HEADERS) -o $@ -c $<

clean:
	@rm -f $(OBJECTS)
	@echo removed binary files

fclean: clean
	@rm -f $(NAME)
	@echo removed library

re: fclean all

.PHONY: all clean fclean re
