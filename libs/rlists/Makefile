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

NAME = librlists.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
OPTIMIZE = yes
PROF = no
DEBUG = no

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

# Headers
INC_PATH = includes
INC_FILES = rlists.h \
	rlists_structs.h \
	rlists_typedefs.h
HEADERS = $(INC_FILES:%.h=$(INC_PATH)/%.h)
CFLAGS += $(addprefix -I,$(INC_PATH))

# Sources
SRC_PATH = src
vpath %.c $(SRC_PATH)
SOURCES = lists_converters.c \
		  lists_finds.c \
		  lists_inits.c \
		  lists_iterators.c \
		  lists_removes.c \
		  lists_removes_functors.c \
		  lists_process_functors.c

# Objects
OBJ_PATH = obj
OBJECTS = $(addprefix $(OBJ_PATH)/, $(SOURCES:%.c=%.o))

# Test
TEST_NAME = tests_rlists
TEST_PATH = test
TEST_HEADERS = $(TEST_PATH)/tinytest.h
TEST_CFLAGS = $(addprefix -I,$(TEST_PATH)) -L$(shell pwd) -lrlists
TEST_SOURCES = test_lists_inits.c 
TEST_OBJECTS = $(addprefix $(OBJ_PATH)/, $(TEST_SOURCES:%.c=%.o))


# Rules
all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $@ $^
	@ranlib $@
	@echo library linked correctly

$(OBJECTS): $(HEADERS) | $(OBJ_PATH)
$(OBJECTS): $(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@-mkdir -p $@

.PHONY: check test

$(TEST_OBJECTS): $(TEST_HEADERS) $(NAME)
$(TEST_OBJECTS): $(OBJ_PATH)/%.o: $(TEST_PATH)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

check: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $(TEST_NAME) $^ $(TEST_CFLAGS)
	./$(TEST_NAME)


.PHONY: clean fclean re

clean:
	@rm -rf $(OBJ_PATH)
	@echo removed binary files

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TEST_NAME)
	@echo removed library
	@echo removed test

re: fclean all


# Tools
.PHONY: valgrind 

valgrind:
	valgrind --leak-check=full ./$(NAME)
