#include<stdio.h>
#include<stdlib.h>
#include"ex2.h"
#define Max_Height 5


Node create(Element e,int c, int num, int height) {
	Node n = (Node)malloc(sizeof(struct node));
	int count=1;
	n->x = num;
	n->e = e;
	//printf("%d->",n->x);

	if(height==Max_Height) {
		return n;
	}
	n->i = createIterator(c);
	Iterator temp = n->i;
	while(hasMoreElements(temp)) {
		int r = rand() % 11;
		Element e = getNextElement(temp);
		e->next = create(e, r,num*10+count++,height+1);
	}

	return n;
}

Node createTree(int c) {
	Iterator i = createIterator(1);
	return create(getNextElement(i),c,0,0);
}

int isEmptyTree(Tree t) {
	if(t==NULL || t->e==NULL) {
		return 1;
	}
	return 0;
}

Element getRootVal(Tree t) {
	return t->e;
}

Iterator getChildren(Tree t) {
	if(isEmptyTree(t)) return NULL;
	return t->i;	
}
