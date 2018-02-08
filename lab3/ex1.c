#include<stdio.h>
#include<stdlib.h>
int bits=1;


void p(int n) {
	int pilani=1;
	printf("n-%u\n", &n);

	p(n+1);
	
}

void h() {


	if(bits==1) {
		bits--;
		p(0);
	}
	int hyderabad=3;
	printf("h-%p\n", &hyderabad);
}

void g() {
	int goa=2;
	printf("g-%p\n", &goa);
	h();
}

int main() {
	p(0); //terminates when 8MB size is reached for stack
	return 0;
}
