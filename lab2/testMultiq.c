#include "multiq.h"
#include<stdio.h>
#include<stdlib.h>

void main() {
	FILE *fp; 
	fp = fopen("input100.txt","r");	
	MultiQ q = createMQ(10);
	print(q);
	q = loadData(q, fp);
	print(q);
	q = testDel(q, 60);
	print(q);
	Task t = abc(1000, 5);
	q = addMQ(q, t);
	print(q);
	printf("%d", sizeMQbyPriority(q,5));
}
