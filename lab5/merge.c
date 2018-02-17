#include "ex1.h"
#include<stdio.h>
#include<stdlib.h>

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]) {
	int x=0,y=0,z=0;
	for(;z<sz1+sz2;z++) {
		if(x==sz1) {
			for(;y<sz2;z++,y++) {
				Ls[z]=Ls2[y];
			}
			break;
		}
		if(y==sz2) {
			for(;x<sz1;z++,x++) {
				Ls[z]=Ls1[x];
			}
			break;
		}
		if(Ls1[x].cgpa<Ls2[y].cgpa)	{
			Ls[z]=Ls1[x];
			x++;
		} else {
			Ls[z]=Ls2[y];
			y++;
		}
	}
}

