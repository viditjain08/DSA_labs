#include"cycle.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>
extern int heap;
#define sizeoflist 1000
tempptr createList(int N) {
	tempptr A = myalloc(sizeof(struct list));
	List l;
	l = A.ptr;
	l->head=NULL;
	Element prev=NULL;
	for(int i=0;i<N;i++) {
		tempptr B = myalloc(sizeof(struct element));
		Element e;
		e = B.ptr;
		if(prev!=NULL) {
			prev->next=e;
		} else {
			l->head = e;
		}
		e->next=NULL;
		e->num=rand()%(sizeoflist);
		prev = e;
		
	}
	return A;
}

tempptr createCyclic(tempptr ls) {
    srand(time(0));
	int i=rand()%2;
	List l = ls.ptr;
	if(i==0) {
		int r = rand()%(sizeoflist);
		Element temp=l->head;
		Element last=l->head;
		if(last==NULL) { return ls; }
		for(;(last->next)!=NULL;last=last->next);
		int count=0;
		for(;temp!=NULL;temp=temp->next) {
			if(count==r) {
				last->next=temp;
				break;
			}
			count++;
		}
	}
	return ls;
}
