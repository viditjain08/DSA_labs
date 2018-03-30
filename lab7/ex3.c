#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ex1.h"
#include"ex3.h"

void prof(Hash h, char** s) {

	for(float m=10;m<=100;m+=10) {
		printf("Lookup Cost for %d%c entries-%d\n",(int)m,'%',lookupAll(h,s,m));
	}
}

void cleanup(FILE* fp, Hash h, char **s) {
	char *tempstr = (char*)malloc(sizeof(char)*30);
	while(fscanf(fp, "%s",tempstr)!=-1) {
		int ind = hash(tempstr,7507,5000);
		Rec temp = (h->arr)[ind];
		Rec prev = temp;
		while(temp!=NULL) {
			if(strcmp(tempstr,s[temp->index])==0) {
				h->elementcount--;
				if(prev==temp) {
					(h->arr)[ind]=temp->next;
					free(temp);
					break;
				} else {
					prev->next=temp->next;
					free(temp);
					break;
				}
			}
		prev = temp;
		temp=temp->next;
		}
	}
	printf("After cleanup:\n");
	prof(h, s);
}
