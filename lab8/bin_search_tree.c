#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ex1.h"

Tree add(Tree t, int x) {
	Tree temp = t;
	Node n = (Node)malloc(sizeof(struct _node));
	n->value = x;
	n->left=NULL;
	n->right=NULL;
	n->h_info = 0;
	while(1) {
		if(x<=temp->value) {
			if(temp->left==NULL) {
				temp->left=n;
				break;
			} else {
				temp=temp->left;
			}
		} else {
			if(temp->right==NULL) {
				temp->right=n;
				break;
			} else {
				temp=temp->right;
			}
		}
	}
	return t;
}

Tree formTree() {
	srand(time(0));
	Tree t = (Tree)malloc(sizeof(struct _node));
	t->value = 150+rand()%21;
	t->left=NULL;
	t->right=NULL;
	t->h_info=0;
	for(int i=1;i<10000;i++) {
		t = add(t, 150+rand()%21);
	}
	Tree temp = t;
	return t;
}
Node find(Tree t, int x) {
	Tree temp = t;
	while(temp!=NULL) {
		if(x==temp->value) {
			return temp;
		} else if(x<temp->value) {
			temp=temp->left;
		} else {
			temp=temp->right;
		}
	}
	return NULL;
}
Tree delete(Tree t, int x) {
	Node temp=t;
	Node new = (Node)malloc(sizeof(struct _node));
	int flag=1;
	new->right = t;
	Node prev=new;
	while(temp!=NULL) {
		if(x<temp->value) {
			prev = temp;
			flag=0;
			temp = prev->left;
		} else if(x>temp->value) {
			prev = temp;
			flag=1;
			temp=prev->right;
		} else {
			if(temp->left==NULL && temp->right==NULL) {
				if(flag==0) {
					prev->left=NULL;
				} else {
					prev->right=NULL;
				}
				free(temp);
				break;
			} else if(temp->left==NULL) {
				Node temp2 = temp;
				temp=temp->right;
				if(flag==0) {
					prev->left=temp;
				} else {
					prev->right=temp;
				}
				free(temp2);
				break;
			} else if(temp->right==NULL) {
				Node temp2 = temp;
				temp=temp->left;
				if(flag==0) {
					prev->left=temp;
				} else {
					prev->right=temp;
				}
				free(temp2);
			} else {
				Node temp2 = temp->right;
				if(temp2->left==NULL) {
					temp->value=temp2->value;
					temp->right=temp2->right;
					free(temp2);
					flag=0;
					prev=temp;
					temp=temp->left;
				} else {
					Node prev2;
					while(temp2->left!=NULL) {
						prev2=temp2;
						temp2=temp2->left;
					}
					prev2->left=temp2->right;
					temp->value=temp2->value;
					free(temp2);
					flag=0;
					prev=temp;
					temp=temp->left;
				}
			}
		}

	}
	t = new->right;
	free(new);
	return t;
}



