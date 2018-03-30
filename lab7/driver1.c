#include<stdio.h>
#include"ex1.h"
#include"ex3.h"
int main() {
	char s[10] = "abcd";
	printf("Hash value of %s = %d\n",s, hash(s,10,20));
	char* st[10] = {"abcd","efghH","ijkl","mnop"};
	printf("Number of collisions=%d\n",colcount(st,10,20));
	FILE* fp; 
	fp = fopen("aliceinwonderland.txt","r");
	char** book = parse(fp);
	profiling(book);
	Hash h = create(5000);
	//h = insert(h,book,0);
	//h = insert(h,book,0);
	printf("Insertion Cost-%d\n",insertAll(h,book));
	char a[] = "small";
	Rec r = lookup(h, a, book);
	printf("Lookup Cost-%d\n",h->queryingcost);
	//int m = 5;
	//printf("Lookup Cost for %d%c entries-%d\n",m,'%',lookupAll(h,book,m));
	prof(h, book);
	FILE* f;
	f = fopen("stopwords.txt","r");
	cleanup(f, h, book);
}
