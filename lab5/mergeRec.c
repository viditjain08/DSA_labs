#include "ex1.h"
#include<stdio.h>
#include<stdlib.h>

void mergeRec(Element Ls[], int low, int high) {
	int mid=(low+high)/2;
	int x=0,y=0;
	if(low==high) {
		return;
	}
	mergeRec(Ls, low, mid);
	mergeRec(Ls, mid+1, high);
	Element* temp = (Element*)malloc(sizeof(Element)*(high-low+1));
	merge(Ls+low,mid-low+1,Ls+mid+1,high-mid,temp);
	for(int i=0;i<high-low+1;i++) {
		Ls[i+low] = temp[i];
	}
	free(temp);	
}

