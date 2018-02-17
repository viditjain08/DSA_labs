#include<stdio.h>
#include<stdlib.h>
#include"ex3.h"
#include"ex1.h"

void split(FILE* fp, int total, int k) {
	for(int i=0;i<total/k;i++) {
		char filename[25];
        sprintf(filename, "temp%d.txt",i);
		FILE* f1 = fopen(filename, "w");
		Element* arr = (Element*)malloc(sizeof(Element)*k);
		for(int j=0;j<k;j++) {
			fscanf(fp, "%[^,],%f\n", arr[j].name, &arr[j].cgpa);
		}
		mergeRec(arr, 0, k-1);
		for(int j=0;j<k;j++) {
			fprintf(f1, "%s,%f\n", arr[j].name, arr[j].cgpa);
		}
		fclose(f1);
		free(arr);
	}
}

void mergefiles(FILE* f1, FILE* f2) {
	int i=0;
	FILE* fp1;
	while(1) {
		char filename[25];
        sprintf(filename, "temp%d.txt",i);
		if(fp1 = fopen(filename, "r")) {
			i++;
		} else {
			fp1 = fopen(filename, "w");
			break;
		}
	}
	Element temp1, temp2;
	fscanf(f1, "%[^,],%f\n", temp1.name, &temp1.cgpa);
	fscanf(f2, "%[^,],%f\n", temp2.name, &temp2.cgpa);
	while(1) {
		if(temp1.cgpa<temp2.cgpa) {
			fprintf(fp1, "%s,%f\n", temp1.name, temp1.cgpa);
			if(fscanf(f1, "%[^,],%f\n", temp1.name, &temp1.cgpa)==-1) {
				fprintf(fp1, "%s,%f\n", temp2.name, temp2.cgpa);
				while(fscanf(f2, "%[^,],%f\n", temp2.name, &temp2.cgpa)!=-1) {
					fprintf(fp1, "%s,%f\n", temp2.name, temp2.cgpa);
				}
				break;
			}
		} else {
			fprintf(fp1, "%s,%f\n", temp2.name, temp2.cgpa);
			if(fscanf(f2, "%[^,],%f\n", temp2.name, &temp2.cgpa)==-1) {
				fprintf(fp1, "%s,%f\n", temp1.name, temp1.cgpa);
				while(fscanf(f1, "%[^,],%f\n", temp1.name, &temp1.cgpa)!=-1) {
					fprintf(fp1, "%s,%f\n", temp1.name, temp1.cgpa);
				}
				break;
			}
		}
	}
	fclose(fp1);
		
}
