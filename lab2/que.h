struct element {
    struct element* next;
    int priority;
    int tid;
};

struct queue {
    struct element* head;
    struct element* tail;
};
typedef struct queue* Queue;
typedef struct element* Element;

enum boolean {True = 1, False = 0}; 
typedef enum boolean Boolean;
Queue newQ(); // returns an empty Queue
Boolean isEmptyQ(Queue q); // tests whether q is empty
Queue delQ(Queue q); // deletes the element from the front of the Queue; returns the modified Queue
Element front(Queue q); // returns the element from the front of the Queue;
Queue addQ(Queue q , Element e); // adds e to the rear of the Queue; returns the modified Queue
int lengthQ(Queue q);

void trav(Queue q);
Element abc(int k, int j);
