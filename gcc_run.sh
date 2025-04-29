#! /bin/bash
gcc -o out/a.out $@
cd out/
./a.out
cd ..
