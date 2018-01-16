#include "SeqList.h"
#include<stdlib.h>
#include<stdio.h>

SeqList merge(SeqList a, SeqList b) {
	Element e1 = a->head;
	Element e2 = a->head;
	while(e1!=NULL) {
		printf("%d",e1->key);
		e2 = e1;
		e1=e1->next;
		b = insertInOrder(b, e2);
	}

	return b;
}

SeqList sort(SeqList sl) {
	Element e1 = sl->head;
	SeqList a = newList();
	Element e2 = sl->head;
	//printf("%d-%d",sl->head->key,sl->tail->key);
	while(e1!=NULL) {
		//printf("%d",a->count);
		e2=e1;
		e1=e1->next;
		a = insertInOrder(a, e2);

	}
	return a;
}
