#include"cycle.h"
#include<stdio.h>
#include<stdlib.h>
int main() {
	while(1) {
		int x = 10000+rand()%15000;
		tempptr A = myalloc(sizeof(int)*x); 

	}	//terminates when heap=RAM size, hence, hangs the computer

	return 0;
}
