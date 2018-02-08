#!/bin/bash
gcc -c cycle.h
gcc -c cycle2.c
gcc -c ex2.c
gcc -c ex3.c
gcc -c driver.c
gcc -pg -o exe cycle.h cycle2.c ex2.c ex3.c driver.c ex5.c
./exe
