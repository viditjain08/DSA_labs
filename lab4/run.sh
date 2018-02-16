#!/bin/bash
gcc -c ex1.c
gcc -c ex2.c
gcc -c ex2driver.c
gcc -c info.h
gcc -pg -o exe info.h ex1.c ex2.c ex2driver.c
./exe
