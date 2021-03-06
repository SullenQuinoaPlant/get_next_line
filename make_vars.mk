ifndef ROOT
	ROOT = .
endif

NAME = getnextline
LIBNAME = lib$(NAME)
TARGET = get_next_line

SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/objects
LIB_DIR := $(ROOT)/libs
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes

DEPENDENCIES := libft

#CC = gcc-8.2.0
CC = gcc
CFLAGS_MORE = -g
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)
CFLAGS += $(CFLAGS_MORE)


UTEST_DIR := $(ROOT)/unit-tests
