struct seqList {
	struct element *head;
	struct element *tail;
	int count;
};

struct element {
	int key;
	struct element *next;
};

typedef struct element * Element;
typedef struct seqList * SeqList;

SeqList newList();
SeqList insertInOrder(SeqList sl, Element e);
SeqList insertAtFront(SeqList sl, Element e);
SeqList insertAtEnd(SeqList sl, Element e);
SeqList delete(SeqList sl, Element e);
SeqList deleteAtFront(SeqList sl);
Element find(SeqList sl, int k);
void trav(SeqList sl);
Element abc(int k);
SeqList merge(SeqList a, SeqList b);
SeqList sort(SeqList sl);
