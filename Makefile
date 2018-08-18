ifndef ROOT
	ROOT := .
	include $(ROOT)/make_vars.mk
endif


#######
#CORE :

include Makefile.mk


#######
#LIBS :

include libs/Makefile

########
#TESTS :

include unit-tests/Makefile
