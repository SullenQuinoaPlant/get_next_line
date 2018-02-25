#!/bin/bash

git clone https://github.com/clibs/cmocka.git cmocka_download
mkdir -p cmocka_build
cd cmocka_build && cmake ../cmocka_download && make
cd ..
cp cmocka_download/include/cmocka.h $LIBS_I
cp cmocka_build/src/libcmocka* $LIBS_L
rm -rf cmocka_download
rm -rf cmocka_build
echo "exiting cmocka installation script"
