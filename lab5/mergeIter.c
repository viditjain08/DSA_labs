#include "ex1.h"
#include<stdio.h>
#include<stdlib.h>

void mergeIter(Element Ls[], int low, int high) {
	int size = high-low+1;
	for(int x=2;x<=size;x*=2) {
		Element* temp = (Element*)malloc(sizeof(Element)*x);
		for(int y=0;y<size/x;y++) {
			merge(Ls+low+x*y,x/2,Ls+low+x*y+x/2,x/2,temp);
			for(int i=0;i<x;i++) {
				Ls[x*y+i]=temp[i];
			}
		}
		free(temp);
	}
	
}
