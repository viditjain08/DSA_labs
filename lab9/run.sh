#!/bin/bash
if [ $1 = "linkedlist" ]
then
echo LINKED LIST
if [ $2 = "bft" ]
then
echo BREADTH FIRST TRAVERSAL
gcc -c -D __LINK ex1_linked.c driver.c ex2.c ex3_bft.c
gcc driver.o ex1_linked.o ex2.o ex3_bft.o -o abc
else
echo DEPTH FIRST TRAVERSAL
gcc -c -D __LINK ex1_linked.c driver.c ex2.c ex3_dft.c
gcc driver.o ex1_linked.o ex2.o ex3_dft.o -o ab
fi
else
echo DYNAMIC ARRAY
if [ $2 = "bft" ]
then
echo BREADTH FIRST TRAVERSAL
gcc -c -D __ARR ex1_dynamic.c driver.c ex2.c ex3_bft.c
gcc driver.o ex1_dynamic.o ex2.o ex3_bft.o -o abc
else 
echo DEPTH FIRST TRAVERSAL
gcc -c -D __ARR ex1_dynamic.c driver.c ex2.c ex3_dft.c
gcc driver.o ex1_dynamic.o ex2.o ex3_dft.o -o abc
fi
fi
#gcc -c -D __ARR driver.c ex1_dynamic.c 
./abc
