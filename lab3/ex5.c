#include"cycle.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>
extern int heap;
#define sizeoflist 1000000

tempptr makeCircularList(tempptr Ls) {
	int circular = testCyclic(Ls);

	if(!circular) {
		List l = Ls.ptr;
		Element temp = l->head;
		if(temp==NULL) {
			return Ls;
		}
		for(;temp->next!=NULL;temp=temp->next);
		temp->next = l->head;
		return Ls;

	} else {

		tempptr a;
		a.size = sizeof(struct list);
		List l = Ls.ptr;
		Element temp = l->head;
		if(temp==temp->next) {
			return Ls;
		}

		int flag=0;

		while(1) {
			temp=l->head;
			Element tnext = temp->next;
			Element n = temp->next;
			Element n2;
			for(;n!=l->head;temp=n, n=n2) {
				n2=n->next;
				n->next=temp;
			}
			n->next=temp;
			if(temp==tnext) {
				a.ptr=l->head;
				myfree(a);
				l->head=tnext;
			}	else {
				if(flag%2!=0) {
					int x = testCyclic(Ls);
				}
				printf("Heap size after making list completely circular- %d\n", heap);
				return Ls;
			}
			flag++;
		}
	}
}
