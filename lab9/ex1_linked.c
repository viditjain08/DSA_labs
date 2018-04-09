#include<stdio.h>
#include<stdlib.h>
#include"node.h"

int hasMoreElements(Iterator it) {
	if(it->current_size!=0) {
		return 1;
	}
	it->current=it->start;
	it->current_size = it->total_size;
	return 0;
}

Element getNextElement(Iterator it) {
	if(it->total_size==0) {
		return NULL;
	}
	if(it->current!=NULL) {
		Element e = it->current;
		it->current_size--;
		it->current=(it->current)->e_next;
		return e;
	}
	return NULL;
}

Iterator createIterator(int c) {
	Iterator i=(Iterator)malloc(sizeof(struct iter));
	Element temp;
	i->total_size=c;
	i->current_size=c;
	i->current=(Element)malloc(sizeof(struct element));
	i->start=i->current;
	temp = i->current;
	for(int x=1;x<c;x++) {
		temp->e_next=(Element)malloc(sizeof(struct element));
		temp=temp->e_next;
	}
	temp->e_next=NULL;
	return i;
}


