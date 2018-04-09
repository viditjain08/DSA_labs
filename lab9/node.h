typedef struct node* Node;
typedef struct element* Element;
typedef Node Tree;
typedef struct iter* Iterator;

#ifdef __LINK
#include"linked.h"
#else
#include"dynamic.h"
#endif

struct iter {
	int total_size;
	int current_size;
	Element start;
	Element current;
};

struct node {
	int x;
	Iterator i;
	Element e;
};

int hasMoreElements(Iterator it);
Element getNextElement(Iterator it);
Iterator createIterator(int c);
Iterator copyIterator(Iterator i);
