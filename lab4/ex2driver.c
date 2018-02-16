#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include"info.h"

int main(int argc, char *argv[]) {
	Info arr = readfn(argv[1]);
	int size = getSize(arr);
	printf("%d\n", size);
	struct timeval t1, t2;
	double time;
	gettimeofday(&t1, NULL);
	printf("%lld-%lld-%lld\n", arr[0].cardno, arr[1].cardno, arr[2].cardno);
	unsigned int k = insertion(arr, size);
	unsigned int l = &size;
	printf("%lld-%lld-%lld", arr[0].cardno, arr[1].cardno, arr[2].cardno);
	gettimeofday(&t2, NULL);

	time = (t2.tv_sec - t1.tv_sec) * 1000.0;
	time += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("\n%lf", time);
	printf("\n%u",(l-k));
	return 0;
}
