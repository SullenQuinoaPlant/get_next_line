.PHONY : all
all : $(LIBNAME)

.PHONY : $(LIBNAME)
$(LIBNAME) : $(LIBS_L)/$(LIBNAME).a

$(LIBS_L)/$(LIBNAME).a : $(OBJ_DIR)/$(TARGET).o
	ar rcs $@ $<
	sed -e'13s@ @ LIB@' -e'14s@\(# define \)@\1LIB@' $(INC_DIR)/$(TARGET).h > $(LIBS_I)/$(LIBNAME).h


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
