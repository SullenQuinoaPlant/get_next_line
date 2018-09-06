ifndef ROOT
	ROOT = ..
	include $(ROOT)/make_vars.mk
endif


libft :
	git clone\
		--single-branch -b release\
		--depth 1\
		https://github.com/SullenQuinoaPlant/Libft.git\
		$(LIB_DIR)/$@
	cp $(LIB_DIR)/$@/includes/libft.h $(LIBS_I)/

.PHONY : clean-lib*
clean-lib% :
	-rm -rf $(LIB_DIR)/lib$*
	-rm $(LIBS_I)/lib$*.h
	-rm $(LIBS_L)/lib$*.a
