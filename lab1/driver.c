#include "SeqList.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
	SeqList sl = newList();
	Element e = abc(5);
	sl = insertAtFront(sl,e);
	trav(sl);
	sl = insertAtEnd(sl,abc(6));
	trav(sl);
	sl = delete(sl, e);
	trav(sl);
	Element e2 = find(sl,6);
	printf("%d\n",e2->key);
	sl = deleteAtFront(sl);
	trav(sl);
	sl = insertInOrder(sl, abc(5));
	trav(sl);
	sl = insertInOrder(sl, abc(7));
	trav(sl);
	sl = insertInOrder(sl, abc(6));
	trav(sl);

	SeqList a = newList();
	a = insertAtEnd(a, abc(9));
	a = insertAtEnd(a, abc(19));
	a = insertAtEnd(a, abc(4));
	a = insertAtEnd(a, abc(7));
	trav(a);
	a = sort(a);
	trav(a);
	//SeqList b = merge(a, sl);
	//trav(b);
	
}
