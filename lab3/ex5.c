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
		List l = Ls.ptr;
		Element hare = l->head->next;
		Element tort = l->head;
		for(;hare->next!=tort&&hare!=tort;hare=hare->next,tort=tort->next) {
			hare=hare->next;
		}

		int count=1;
		Element temp = tort->next;
		while(temp!=tort) {
			count++;
			temp=temp->next;
		}
		temp = l->head;
		Element temp2 = l->head;
		for(int i=0;i<count;i++) {
			temp=temp->next;
		}
		tempptr a;
		a.size = sizeof(struct element);	
		while(temp2!=temp) {
			a.ptr = temp2;
			temp2=temp2->next;
			temp=temp->next;
			l->head = temp2;
			myfree(a);
		}
		printf("Heap size after making list completely circular- %d\n", heap);
		return Ls;	
	}
}
