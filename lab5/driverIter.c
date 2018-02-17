#include "ex1.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE *fp;
	fp = fopen("1024.txt", "r");
	Element* arr = (Element*)malloc(sizeof(Element)*1024);
	int i=0;
	while(fscanf(fp, "%[^,],%f\n", arr[i].name, &arr[i++].cgpa)!=-1);
	mergeIter(arr, 0, 1023);
	for(int i=0;i<10;i++) {
		printf("%f\n", arr[i].cgpa);
	}
	return 0;
}
