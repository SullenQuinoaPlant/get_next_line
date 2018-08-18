ifndef ROOT
	LIB_DIR = ./libs/objects
	LIB_H_DIR  = ./libs/includes
endif

#nothing to make
all : $(LIBNAME)

$(LIBNAME) : $(OBJ_DIR)/$(TARGET).o
	ar rcs $@.a $<
	mv $@.a $(LIBS_L)/
	mv $(SRC_DIR)/$(TARGET).h $(LIBS_I)/

$(OBJ_DIR)/$(TARGET).o :
	$(CC) $(CFLAGS) $(CFLAGS_MORE)\
		-I $(LIBS_I)\
		-o $@\
		$(SRC_DIR)/$(TARGET).c

clean :
	-rm $(OBJ_DIR)/$(TARGET).o

fclean : clean
	-rm $(LIBS_L)/$(LIBNAME).a
	-rm $(LIBS_I)/$(LIBNAME).h

re : fclean all

.PHONY : re fclean clean all
