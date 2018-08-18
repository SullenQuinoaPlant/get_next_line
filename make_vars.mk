ifndef ROOT
	ROOT = .
endif

NAME = getnextline
LIBNAME = LIB$(NAME)
TARGET = get_next_line

SRC_DIR	:= $(ROOT)/sources
OBJ_DIR := $(ROOT)/sources
LIB_DIR := $(ROOT)/libs
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS_MORE =


UTEST_DIR := $(ROOT)/unit-tests
