NAME = getnextline
LIBNAME = lib$(NAME)
TARGET = get_next_line

SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/sources
LIB_DIR := $(ROOT)
LIBS_L := $(LIB_DIR)
LIBS_I := $(LIB_DIR)

CC = gcc
CFLAGS_MORE =
CFLAGS := -Wall -Wextra -Werror $(CFLAGS_MORE)
