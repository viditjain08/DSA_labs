#include"ex2.h"
typedef struct currentset* currentSet;
struct currentset {
	Node n;
	currentSet next;
};

Node selectNextNode(currentSet);
Iterator identifyMoreNodes(Node);
currentSet addMoreNodes(currentSet, Iterator);
void visitNode(Node n);
void traverse(Tree t);
