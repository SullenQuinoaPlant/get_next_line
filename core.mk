.PHONY : all
all : $(LIBNAME) header

.PHONY : $(LIBNAME)
$(LIBNAME) : $(LIBS_L)/$(LIBNAME).a

$(LIBS_L)/$(LIBNAME).a : $(OBJ_DIR)/$(TARGET).o
	ar rcs $@ $<

.PHONY : header
header : $(LIBS_I)/$(LIBNAME).h
$(LIBS_I)/$(LIBNAME).h : $(INC_DIR)/$(TARGET).h
	sed \
		-e '4s@\([a-z0-9.]*\)   @lib\1@'\ 
		-e '13,14s@\([A-Z])\)@LIB\1@'\
		$< > $@


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
