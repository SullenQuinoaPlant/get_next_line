#!/bin/bash

git clone https://github.com/clibs/cmocka.git cmocka_download
mkdir -p cmocka_build
cd cmocka_build
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_HERE ../cmocka_download
make
make install
cd ..
(
	rm -rf cmocka_download -v
	rm -rf cmocka_build -v
) &> /dev/null
echo "exiting cmocka installation script"
