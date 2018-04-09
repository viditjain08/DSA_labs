#include<stdio.h>
#include<stdlib.h>
#include"ex3.h"
#include<time.h>

void main() {
	srand(time(0));
	Node n = createTree(5);
	printf("\n\n");
	traverse(n);
}
