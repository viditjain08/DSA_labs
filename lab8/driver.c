#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ex1.h"

void p(Tree t) {
	if(t==NULL) return;
	printf("%d\t",t->value);
	p(t->left);
	p(t->right);
}
void main() {
	Tree t = formTree();
	//p(t);
	printf("\n%d\n\n",t->value);
	t = delete(t,160);
	p(t);
	//Node n = find(t, 160);
	//t = delete(t,160);
	//n = find(t,160);
}
