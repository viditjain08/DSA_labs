#include "SeqList.h"
#include<stdlib.h>
#include<stdio.h>
SeqList newList() {
	SeqList s = (SeqList)malloc(sizeof(struct seqList));
	s->count=0;
	s->head=NULL;
	s->tail=NULL;
	return s;
}

SeqList insertInOrder(SeqList sl, Element e) {
	if(sl->head==NULL) {
		sl->head=e;
		sl->tail=e;
		sl->count=1;
		e->next=NULL;
		return sl;
	}
	sl->count++;
	Element temp = sl->head;
	Element prev = sl->head;
	for(;temp!=NULL&&temp->key<e->key;prev=temp,temp=temp->next);
	if(temp==sl->head) {
		sl->head=e;
	} else {
		prev->next=e;
	}
	e->next=temp;
	if(temp==NULL) { sl->tail=e; }

	return sl;
}

SeqList insertAtFront(SeqList sl, Element e) {
	e->next=sl->head;
	sl->head=e;
	if(sl->count==0) {
		sl->tail=e;
	}
	sl->count++;
	return sl;
}

SeqList insertAtEnd(SeqList sl, Element e) {
	e->next=NULL;
	sl->count++;
	if(sl->count==1) {
		sl->head=e;
		sl->tail=e;
		return sl;
	}
	sl->tail->next=e;
	sl->tail=e;
	return sl;
}

SeqList delete(SeqList sl, Element e) {
	Element s = sl->head;
	if(s==NULL) {
		return sl;
	}
	Element prev = sl->head;
	if(sl->head==e) {
		sl->head=e->next;
		sl->count--;
		if(sl->count==0) { sl->tail=NULL; }
		return sl;
	}	
	for(;s!=NULL&&e!=s;prev=s,s=s->next);
	if(s==NULL) {
		return sl;
	}
	prev->next=s->next;
	sl->count--;
	if(sl->tail==e) { sl->tail=prev; }
	return sl;
}

SeqList deleteAtFront(SeqList sl) {
	if(sl->count==0) {
		return sl;
	} else if(sl->count==1) {
		sl->count--;
		sl->head=NULL;
		sl->tail=NULL;
	} else {
		sl->head=sl->head->next;
		sl->count--;
	}
	return sl;

}

Element find(SeqList sl, int k) {
	Element e = sl->head;
	for(;e!=NULL;e=e->next) {
		if(e->key==k) {
			return e;
		}
	}
	return NULL;
}
void trav(SeqList sl) {
	Element e = sl->head;
	for(;e!=NULL;e=e->next) {
		printf("%d->",e->key);
	}
	printf("NULL\n");
}

Element abc(int k) {
	Element e = (Element)malloc(sizeof(struct element));
	e->key=k;
	e->next=NULL;
	return e;
}	
	
