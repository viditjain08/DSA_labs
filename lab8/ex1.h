typedef struct _node* Node;
typedef Node Tree;

struct _node {
	int value: 9;
	Tree left;
	Tree right;
	int h_info: 4;  // no use in binary search tree
};

Tree add(Tree, int);
Node find(Tree, int);
Tree delete(Tree, int);
Tree formTree();
