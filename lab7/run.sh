#!/bin/bash
gcc -c ex1.h
gcc -c ex1.c
gcc -c driver1.c
gcc -c ex2.h
gcc -c ex2.c
gcc -c ex3.h
gcc -c ex3.c
gcc -o abc ex1.c ex1.h ex2.h ex2.c ex3.h ex3.c driver1.c
./abc
