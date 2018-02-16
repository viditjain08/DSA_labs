#include<stdio.h>
#include<stdlib.h>
#include "info.h"

Info insertInOrder(Info arr, int size, info c) {
	int i=0;
	info temp = c;
	info temp1 = c;	
	while(i<size) {
		if(temp.cardno<arr[i].cardno) {
			temp1 = arr[i];
			arr[i] = temp;
			temp = temp1;
		}
	i++;
	}

	arr[i]=temp;
	return arr;
}

unsigned int insertion(Info arr, int size) {
	if(size==1) {
		unsigned int x = &size;
		return x;
	}
	unsigned int k = insertion(arr, size-1);
	insertInOrder(arr, size-1, arr[size-1]);

	return k;
}

int getSize(Info arr) {
	int i=0;
	while(arr[i].cardno) {
		i++;
	}
	return i;
}
