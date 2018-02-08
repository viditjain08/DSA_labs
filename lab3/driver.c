#include"cycle.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>
extern int heap;
#define sizeoflist 1000

int main() {
	struct timeval t1, t2;
	double elapsedTime;
	tempptr t = createList(sizeoflist);
	FILE * fp;
	fp = fopen ("heap.txt","w");
	fprintf (fp, "Heap space: %d\n", heap);
	fclose(fp);
	t = createCyclic(t);
	gettimeofday(&t1, NULL);
	printf("%d\n", testCyclic(t));
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec);
	printf("Time time for %d elements is %f us. Heap size- %d\n", sizeoflist, elapsedTime, heap);
	tempptr a = makeCircularList(t);
	return 0;
}
