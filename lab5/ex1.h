typedef struct {
	char name[100];
	float cgpa;
} Element;

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
void mergeRec(Element Ls[], int low, int high);
void mergeIter(Element Ls[], int low, int high);
