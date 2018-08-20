ifndef ROOT
	ROOT = .
	include make_vars.mk
endif

all : $(LIBNAME)

$(LIBNAME) : $(OBJ_DIR)/$(TARGET).o
	ar rcs $@.a $<
	mv $@.a $(LIBS_L)/
	cp $(SRC_DIR)/$(TARGET).h $(LIBS_I)/$(LIBNAME).h

$(OBJ_DIR)/$(TARGET).o :
	$(CC) $(CFLAGS) $(CFLAGS_MORE)\
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
