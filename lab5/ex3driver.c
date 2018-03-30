#include<stdio.h>
#include<stdlib.h>
#include"ex1.h"
#include"ex3.h"
#include <sys/time.h>

int main() {
	FILE* fp;
	struct timeval t1, t2;
	double time;
	gettimeofday(&t1, NULL);
	fp = fopen("10240.txt", "r");
	split(fp, 10240, 512);
	FILE* f1, *f2;
	f1 = fopen("temp0.txt", "r");
	f2 = fopen("temp1.txt", "r");
	mergefiles(f1, f2);
	fclose(f1);
	fclose(f2);
	for(int i=2;i<20;i++) {
		char filename1[25], filename2[25];
		sprintf(filename1,"temp%d.txt",i);
		sprintf(filename2,"temp%d.txt",i+18);
		f1 = fopen(filename1, "r");
		f2 = fopen(filename2, "r");
		mergefiles(f1,f2);
		fclose(f1);
		fclose(f2);
	
	}
	gettimeofday(&t2, NULL);
	time = (t2.tv_sec - t1.tv_sec) * 1000.0;
	time += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Time -%lf", time);
	return 0;
}
