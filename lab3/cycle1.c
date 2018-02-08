#include "cycle.h"
#include<stdio.h>
#include<stdlib.h>

int testCyclic(tempptr s) {
	List l;
	l = s.ptr;
	Element hare = l->head;
	Element tort = l->head;
	if(hare==NULL||hare->next==NULL) {
		return 0;
	} else if(hare->next==hare) {
		return 1;
	}
	int flag=0;
	for(;hare!=NULL && tort!=NULL;hare=hare->next,tort=tort->next) {
		if(hare==NULL) {
			return 0;
		}
		if(flag!=0) {
			if(hare==tort||hare->next==tort) {
				return 1;
			}
		}
		flag=1;
		hare=hare->next;
	}
	return 0;
}
