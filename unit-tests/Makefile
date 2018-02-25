ifndef ROOT
	ROOT = ..
	include $(ROOT)/make_vars.mk
endif

TEST_SRCS := $(wildcard $(UTEST_DIR)/*.test.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
BUILD_STAMPS := $(TEST_OBJS:.o=.build.stamp)
EXECUTION_STAMPS := $(TEST_OBJS:.o=.execution.stamp)

CC = gcc
CFLAGS_MORE =
CFLAGS = -fno-builtin #-Wall -Wextra -Werror
CFLAGS += $(CFLAGS_MORE)



.PHONY : unit-tests ut
unit-tests ut : list_tests build_tests run_tests




############
#BUILD TESTS

.PHONY : build_tests
build_tests : cmocka $(TEST_OBJS)

.PHONY : cmocka
cmocka : 
	if $(CC) $(CFLAGS)\
		-I $(LIBS_I) -L $(LIBS_L)\
	 	$(UTEST_DIR)/boilerplate.c\
		 -lcmocka -o test.o; then\
			rm test.o;\
			echo "cmocka already installed";\
	else\
		$(MAKE) -C $(UTEST_DIR)/cmocka/;\
		cp $(UTEST_DIR)/cmocka/libcmocka* $(LIBS_L)/;\
		cp $(UTEST_DIR)/cmocka/cmocka.h $(LIBS_I)/;\
	fi

%.test.o $(UTEST_DIR)/%.test.o : $(UTEST_DIR)/%.test.c $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)\
		-I $(LIBS_I) -I $(SRC_DIR)\
		-D main=testee_main\
		-include $(SRC_DIR)/$*.c\
		$<\
		-L $(LIBS_L)\
		-lcmocka -lft\
		-o $@\
		-Wl,-rpath=$$(readlink -e $(LIBS_L));\
		touch $(UTEST_DIR)/$*.test.build.stamp

%.test.o : %.test.c
	$(CC) $(CFLAGS)\
		-I $(SRC_DIR)\
		-I $(LIBS_I)\
		$<\
		-L $(LIBS_L)\
		-lcmocka -lft\
		-o $@\
		-Wl,-rpath=$$(readlink -e $(LIBS_L));\
		touch $(UTEST_DIR)/$(*F).test.build.stamp

%.test.c : $(UTEST_DIR)/cmocka/my_macro_overlay.h
	@:




############
#RUN TESTS :

.PHONY : run_tests
run_tests : $(EXECUTION_STAMPS)

%.execution.stamp : %.build.stamp
	./$*.o "$$(readlink -e $(UTEST_DIR))"
	touch $@

%.build.stamp :
	@:

###############
#MISCELLANEOUS:

.PHONY : all_unit_tests aut
all_unit_tests aut : clean-tests test



.PHONY : clean-tests
clean-tests :
	-rm $(UTEST_DIR)/*.o
	-rm $(UTEST_DIR)/*.stamp



.PHONY : list_tests
list_tests :
	@echo "source dir is : $(SRC_DIR)"
	@echo "list of test sources:"
	@echo $(TEST_SRCS)
	@echo "list of test objects:"
	@echo $(TEST_OBJS)
