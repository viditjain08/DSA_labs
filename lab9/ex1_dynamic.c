#include<stdio.h>
#include<stdlib.h>
#include"node.h"

int hasMoreElements(Iterator it) {
	if(it->current_size!=0) {
		return 1;
	}
	it->current=it->start;
	it->current_size=it->total_size;
	return 0;
}

Element getNextElement(Iterator it) {
	if(it->total_size==0) {
		return NULL;
	}
	Element e;
	if(it->current_size!=0) {
		e = it->current;
		it->current_size--;
		it->current = (it->current)+1;
	}
	return e;
}

Iterator createIterator(int c) {
	Iterator i = (Iterator)malloc(sizeof(struct iter));
	i->start = (Element)malloc(c*sizeof(struct element));
	i->current = i->start;
	i->current_size=c;
	i->total_size=c;
	return i;
}


