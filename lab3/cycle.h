struct element {
    struct element* next;
    int num;

};

struct list {
    struct element* head;
};

typedef struct list* List;
typedef struct element* Element;

typedef struct {
	int size;
	void* ptr;
} tempptr;

tempptr myalloc(int size);
void myfree(tempptr s);
int testCyclic(tempptr s);
tempptr createList(int N);
tempptr createCyclic(tempptr ls);
tempptr makeCircularList(tempptr Ls);
