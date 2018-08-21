ifndef ROOT
	ROOT = ..
	include $(ROOT)/make_vars.mk
endif


nop :
	@:


libft : $(LIBS_I)/libft.h $(LIBS_L)/libft.a
	git clone\
		--single-branch -b the_lib\
		--depth 1\
		https://github.com/SullenQuinoaPlant/Libft.git\
		$(LIB_DIR)/$@
	cp $(LIB_DIR)/$@/libft.h $(LIBS_I)/

$(LIBS_I)/libft.h :
	@:

$(LIBS_L)/libft.a :
	@:

.PHONY : clean-libft
clean-libft :
	-rm libft
	-rm $(LIBS_I)/libft.h
	-rm $(LIBS_L)/libft.a
