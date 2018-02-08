#include"cycle.h"
#include<stdio.h>
#include<stdlib.h>
int heap=0;

tempptr myalloc(int size) {
	void* ptr = malloc(size);	//returns NULL when fails to allocate
	heap+=size;
	tempptr s;
	s.size = size;
	s.ptr = ptr;
	return s;
}

void myfree(tempptr s) {
	heap-=s.size;
	free(s.ptr);
	}

