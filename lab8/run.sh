#!/bin/bash
gcc -c bin_search_tree.c ex2.c
gcc ex2.o bin_search_tree.o -o abc
./abc
