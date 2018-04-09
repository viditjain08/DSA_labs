#include<stdio.h>
#include<stdlib.h>
#include"ex3.h"

Node selectNextNode(currentSet s) {
	return s->n;
}
Iterator identifyMoreNodes(Node n) {
	return getChildren(n);
}
currentSet addMoreNodes(currentSet s, Iterator i) {

	if(i!=NULL) {
		currentSet temp = s;
		while(temp->next!=NULL) {
			temp=temp->next;
		}
		currentSet new;
		while(hasMoreElements(i)) {
			Element e = getNextElement(i);
			Node n = e->next;
			new = (currentSet)malloc(sizeof(struct currentset));
			new->n = n;
			new->next = NULL;
			temp->next = new;
			temp=temp->next;
		}
	}
	s=s->next;
	return s;
}

void visitNode(Node n) {
	printf("%d-",n->x);
}

void traverse(Tree t) {
	currentSet s = (currentSet)malloc(sizeof(struct currentset));
	s->n = t;
	Node n;
	s->next = NULL;
	while(s!=NULL) {
		n = selectNextNode(s);
		visitNode(n);
		s = addMoreNodes(s, identifyMoreNodes(n));
	} 
}
