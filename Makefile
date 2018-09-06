ifndef ROOT
	ROOT := .
endif


#######
#CORE :
include core.mk

#######
#LIBS :
include libs/Makefile

########
#TESTS :
include unit-tests/Makefile


########
#RELEASE
.PHONY : release
release:
	git clone\
		--depth 1 --single-branch\
		-b release\
		https://github.com/SullenQuinoaPlant/get_next_line.git\
		$(ROOT)/$@/
	cp $(ROOT)/auteur $(ROOT)/$@
	cp -rf $(ROOT)/sources/ $(ROOT)/$@
	cp $(ROOT)/Makefile.mk $(ROOT)/$@/Makefile
	cp $(ROOT)/make_vars_release.mk $(ROOT)/$@/make_vars.mk
	cp $(LIBS_I)/libft.h $(ROOT)/$@/sources/
	cd $(ROOT)/$@ && git add * && git commit -m i && git push

.PHONY : project
project :
	if [ -d "$(ROOT)/$@" ]; then rm -rf "$(ROOT)/$@"; fi
	mkdir $(ROOT)/$@/
	cp $(ROOT)/auteur $(ROOT)/$@
	cp $(ROOT)/sources/* $(ROOT)/$@
	cp $(LIBS_I)/libft.h $(ROOT)/$@
	git clone https://github.com/SullenQuinoaPlant/Libft.git\
		-b the_lib --single-branch --depth 1\
		$(ROOT)/$@/libft
