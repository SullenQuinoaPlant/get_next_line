BUILD_DIR = cmocka_build
SOURCE_DIR = cmocka_source

cmocka : $(BUILD_DIR) $(SOURCE_DIR) build move

build :
	cd $(BUILD_DIR) && cmake ../$(SOURCE_DIR) && make;

move :
	cp $(SOURCE_DIR)/include/cmocka.h .
	cp $(BUILD_DIR)/src/libcmocka* .

$(BUILD_DIR) :
	if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi

$(SOURCE_DIR) :
	if [ ! -d $(SOURCE_DIR) ]; then git clone git://git.cryptomilk.org/projects/cmocka.git $(SOURCE_DIR); fi
	

clean :
	rm libcmocka.so*
	rm cmocka.h
	rm -rf $(BUILD_DIR)
