#!/bin/bash

git clone git://git.cryptomilk.org/projects/cmocka.git
mkdir -p cmocka_build
cd cmocka_build && cmake ../cmocka_download && make
cd ..
cp cmocka_download/include/cmocka.h $LIBS_I
cp cmocka_build/src/libcmocka* $LIBS_L
rm -rf cmocka_download
rm -rf cmocka_build
echo "exiting cmocka installation script"
