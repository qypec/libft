#!/bin/bash

if [ $1 == "clean" ]
then
make -C unit_tests/ fclean
exit
fi

make -C unit_tests/ all
cp -p unit_tests/lib/unit_test unit_tests/unit_test
rm -rf unit_tests/lib/unit_test
./unit_tests/unit_test
