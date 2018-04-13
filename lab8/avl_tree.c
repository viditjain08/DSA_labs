#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ex1.h"
typedef struct stack* Stack;
struct stack {
	Node top;
	Stack next;
};
Stack push(Stack s, Node n) {
	Stack x = (Stack)malloc(sizeof(struct stack));
	x->top=n;
	x->next=s;
	s=x;
	return s;
}
Node pop(Stack* s) {
	Node n=(*s)->top;
	*s=(*s)->next;
	return n;
}

int height(Node x) {
	int h=-1;
	while(x!=NULL) {
		if(x->h_info<=0) {
			x=x->left;
		} else {
			x=x->right;
		}
		h++;
	}
	return h;
}
Tree rotate(Tree t, Node X, Node Y, Node Z, Node parent) {
	Node a,b,c,t0,t1,t2,t3;
	if((Z->left==Y || Z->right==Y)==0 && (Y->left==X || Y->right==X)==0) {
		return t;
	}
	if(Z->left==Y) {
		c = Z;
		t3=Z->right;
		if(Y->left==X) {
			a = X;
			b = Y;
			t0 = X->left;
			t1 = X->right;
			t2 = Y->right;
		} else {
			a = Y;
			b = X;
			t0 = Y->left;
			t1 = X->left;
			t2 = X->right;
		}
	} else {
		a = Z;
		t0 = Z->left;
		if(Y->left==X) {
			b = X;
			c = Y;
			t1 = X->left;
			t2 = X->right;
			t3 = Y->right;
		} else {
			b = Y;
			c = X;
			t1 = Y->left;
			t2 = X->left;
			t3 = X->right;
		}	
	}
	if(t==Z) {
		t=b;
	}
	if(parent!=NULL) {
		if(parent->left==Z) {
			parent->left=b;
		} else {
			parent->right=b;
		}
	}
	b->left=a;
	b->right=c;
	a->left=t0;
	a->right=t1;
	c->left=t2;
	c->right=t3;
	int h0 = height(t0);
	int h1 = height(t1);
	int h2 = height(t2);
	int h3 = height(t3);
	int h_max1, h_max2;
	a->h_info = h1-h0;
	c->h_info = h3-h2;
	if(h0<h1) {
		h_max1=h1;
	} else {
		h_max1=h0;
	}
	if(h2<h3) {
		h_max2=h3;
	} else {
		h_max2=h2;
	}
	b->h_info = h_max2-h_max1;
	return t;
}

Tree add(Tree t, int x) {
	Tree temp = t;
	Node n = (Node)malloc(sizeof(struct _node));
	n->value = x;
	n->left=NULL;
	n->right=NULL;
	n->h_info = 0;
	Stack s = (Stack)malloc(sizeof(struct stack));
	s->top=temp;
	s->next=NULL;
	while(1) {
		int i=rand()%2;
		if(x<temp->value) { i=0;}
		if(x>temp->value) { i=1;}
		if(i==0) {
			if(temp->left==NULL) {
				temp->left=n;
				break;
			} else {
				temp=temp->left;
				s = push(s,temp);
			}
		} else {
			if(temp->right==NULL) {
				temp->right=n;
				break;
			} else {
				temp=temp->right;
				s = push(s,temp);
			}
		}
	}
	Node temp2,temp3=n,temp4=n;
	while(s!=NULL) {
		temp2 = pop(&s);
		int h1 = height(temp2->left);
		int h2 = height(temp2->right);
		temp2->h_info = h2-h1;
		if(temp2->h_info>1 || temp2->h_info<-1) {
			if(s==NULL) {
				t = rotate(t, temp4, temp3, temp2, NULL);
			} else {
				t = rotate(t,temp4,temp3,temp2,s->top);
			}
		}
		temp4 = temp3;	
		temp3 = temp2;
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
	Node abc=find(t,x);
	Node new = (Node)malloc(sizeof(struct _node));
	int flag=1;
	new->right = t;
	Node prev=new;

	while(abc!=NULL) {
		Node temp=t;
		Stack s = (Stack)malloc(sizeof(struct stack));
		s->top=temp;
		s->next=NULL;
		while(temp!=NULL) {
			if(x<temp->value) {
				flag=0;
				prev=temp;
				temp=temp->left;
				s=push(s,temp);
			} else if(x>temp->value) {
				flag=1;
				prev=temp;
				temp=temp->right;
				s=push(s,temp);
			} else {
				if(temp->left==NULL && temp->right==NULL) {
					if(flag==0) {
						prev->left=NULL;
					} else {
						prev->right=NULL;
					}
					free(temp);
				} else if(temp->left==NULL) {
					Node temp2 = temp;
					temp=temp->right;
					if(flag==0) {
						prev->left=temp;
					} else {
						prev->right=temp;
					}
					free(temp2);
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
					s = push(s,temp2);
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
							s = push(s,temp2);
						}
						prev2->left=temp2->right;
						temp->value=temp2->value;
						free(temp2);
						flag=0;
						prev=temp;
						temp=temp->left;
					}	
				}
				break;
			}
		}
		Node n = pop(&s);
		n=NULL;
		Node X,Y,Z;
		while(s!=NULL) {
			Z = pop(&s);
			int h1 = height(Z->left);
			int h2 = height(Z->right);
			Z->h_info = h2-h1;
			if(Z->h_info>1 || Z->h_info<-1) {
				int a;
				if(Z->h_info>1) {
					Y = Z->right;
					if(Y->h_info>0) {
						X = Y->right;
					} else {
						X = Y->left;
					}
					a = Y->h_info;
				} else {
					Y = Z->left;
					if(Y->h_info>0) {
						X = Y->right;
					} else {
						X = Y->left;
					}
				}
				if(s==NULL) {
					t = rotate(t, X, Y, Z, new);
				} else {
					t = rotate(t, X, Y, Z,s->top);
				}
			}
		}
		t = new->right;
		abc=find(t,x);
	}
	free(new);
	return t;
}



