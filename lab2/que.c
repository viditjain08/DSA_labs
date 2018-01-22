#include "que.h"
#include<stdio.h>
#include<stdlib.h>

Queue newQ() {
	Queue q = (Queue) malloc(sizeof(struct queue));
	q->head=NULL;
	q->tail=NULL;
	return q;
}

Boolean isEmptyQ(Queue q) {
	if(q->head==NULL) {
		return True;
	}
	return False;

}

Queue delQ(Queue q) {
	if(q->head==q->tail) {
		q->head=NULL;
		q->tail=NULL;
		return q;
	}
	Element e=q->tail;
	for(;e->next->next!=NULL;e=e->next);
	e->next=NULL;
	q->head=e;
	return q;
}

Element front(Queue q) {
	return q->head;
}

Queue addQ(Queue q , Element e) {
	e->next=q->tail;
	q->tail=e;
	if(q->head==NULL) {
		q->head=e;
	}
	return q;
}

int lengthQ(Queue q) {
	int x=0;
	Element e = q->tail;
	for(;e!=NULL;e=e->next) {
		x++;
	}
	return x;
}

void trav(Queue q) {
	Element e=q->tail;
	for(;e!=NULL;e=e->next) {
		printf("%d->",e->tid);
	}
	printf("NULL\n");
}

Element abc(int k, int j) {
	Element e = (Element) malloc(sizeof(struct element));
	e->next=NULL;
	e->tid=k;
	e->priority=j;
	return e;
}
