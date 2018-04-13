#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ex1.h"

void inorder(Tree t, Node* arr, int k) {
	if(t==NULL) return;
	inorder(t->left, arr, k);
	if(arr[0]==NULL) {
		arr[0]=t;
	}
	for(int i=0;;i++) {
		if(i==k) {
			return;
		}
		if(arr[i]==NULL) {
			if(arr[i-1]->value!=t->value) {
				arr[i]=t;
			}
			break;
		}
	}
	inorder(t->right, arr, k);
}

Node inord(Tree t, int k) {
	Node arr[k+1];
	for(int i=0;i<=k;i++) {
		arr[i]=NULL;
	}
	inorder(t,arr,k);
	return arr[k-1];
}

void rangequery(Tree t, int low, int high) {
	if(t==NULL) return;
	if(t->value>high) {
		rangequery(t->left,low,high);
	} else if(t->value<low) {
		rangequery(t->right,low,high);
	} else {
		rangequery(t->left,low,t->value);
		printf("->%d",t->value);
		rangequery(t->right,t->value,high);
	}
}
int main() {
	Tree t = formTree();
	rangequery(t,155,160);
	return 0;
} 
