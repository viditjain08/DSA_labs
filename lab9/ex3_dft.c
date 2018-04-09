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

	if(i==NULL || hasMoreElements(i)==0) {
		currentSet x = s;
		s=s->next;
		free(x);
		if(s==NULL) {
			return s;
		}
		Iterator new = identifyMoreNodes(s->n);
		s = addMoreNodes(s,new);
	} else {
		currentSet temp = (currentSet)malloc(sizeof(struct currentset));
		Element e = getNextElement(i);
		temp->n = e->next;
		temp->next = s;
		s = temp;
	}
	return s;
}

void visitNode(Node n) {
	printf("%d-",n->x);
}

void traverse(Tree t) {
	printf("\nDepth First Traversal\n");
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
