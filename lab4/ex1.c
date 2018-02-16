#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include "info.h"

Info readfn(char s[10]) {
	struct timeval t1, t2;
	double time;
	gettimeofday(&t1, NULL);
	FILE *fp;
	fp = fopen(s, "r");
	int count=10;
	Info arr = (Info)malloc(count*sizeof(info));
	int i=0;
	while(fscanf(fp, "\"%lld,%[^,],%[^,],%[^,],%[^\"]\"\n", &arr[i].cardno, arr[i].bankcode, arr[i].expiry, arr[i].firstname, arr[i].lastname)!=-1) {
	//printf("%lld\n", arr[i].cardno);
	i++;
	if(i>=count) {
		count+=10;
		arr = (Info)realloc(arr, count*sizeof(info));
	}
	}
	fclose(fp);
	gettimeofday(&t2, NULL);
	time = (t2.tv_sec - t1.tv_sec) * 1000.0;
	time += (t2.tv_usec - t1.tv_usec) / 1000.0;
	FILE *f;
	f = fopen("timeex1.txt","w");
	fprintf(f, "%lf", time);
	return arr;

}

