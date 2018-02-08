#include "cycle.h"
#include<stdio.h>
#include<stdlib.h>

int testCyclic(tempptr s) {
	List l;
	l = s.ptr;
	Element temp = l->head;
	Element prev = l->head;
	if(temp==NULL||temp->next==NULL) {
		return 0;
	} else if(temp->next==temp) {
		return 1;
	}
	temp=temp->next;
	Element temp2 = temp;
	int flag=0;
	for(;temp!=NULL;prev=temp,temp=temp2) {
		temp2 = temp->next;
		if(flag==0) {
			prev->next=NULL;
		}
		temp->next=prev;
		if(l->head==temp) {
			return 1;
		}
		flag++;
	}
	return 0;
}
