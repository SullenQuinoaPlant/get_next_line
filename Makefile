ROOT = .

NAME = getnextline
LIBNAME = lib$(NAME)
TARGET = get_next_line

SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/sources
LIB_DIR := $(ROOT)
LIBS_L := $(LIB_DIR)
LIBS_I := $(INC_DIR)

CC = gcc
CFLAGS_MORE =
CFLAGS := -Wall -Wextra -Werror $(CFLAGS_MORE)
.PHONY : all
all : $(LIBNAME) header

.PHONY : $(LIBNAME)
$(LIBNAME) : $(LIBS_L)/$(LIBNAME).a

$(LIBS_L)/$(LIBNAME).a : $(OBJ_DIR)/$(TARGET).o
	ar rcs $@ $<

.PHONY : header
header : $(LIBS_I)/$(LIBNAME).h
$(LIBS_I)/$(LIBNAME).h : $(INC_DIR)/$(TARGET).h
	sed -e "4s/\([a-z][a-z0-9._]*\) /libgetnextline\.h/" -e "13,14s/[A-Z_][A-Z_]*/LIBGETNEXTLINE_H/" $< > $@


$(OBJ_DIR)/$(TARGET).o : $(SRC_DIR)/$(TARGET).c 
	$(CC) $(CFLAGS)\
		-I $(LIBS_I)\
		-o $@\
		-c $(SRC_DIR)/$(TARGET).c

clean :
	-rm $(OBJ_DIR)/$(TARGET).o

fclean : clean
	-rm $(LIBS_L)/$(LIBNAME).a
	-rm $(LIBS_I)/$(LIBNAME).h

re : fclean all

.PHONY : re fclean clean all
