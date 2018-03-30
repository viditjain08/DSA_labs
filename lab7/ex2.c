#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ex1.h"
#include"ex2.h"

Hash create(int tsize) {
	Hash h = (Hash)malloc(sizeof(struct hash));
	h->elementcount=0;
	h->insertioncost=0;
	h->queryingcost=0;
	h->arr = (Rec*)malloc(sizeof(Rec)*tsize);
	return h;
}

Hash insert(Hash h,char** s,int index) {
	int count=1;
	int ind = hash(s[index],7507,5000);
	Rec temp = (h->arr)[ind];
	Rec record = (Rec)malloc(sizeof(struct rec));
	record->next=NULL;
	record->index=index;
	record->count=1;
	if(temp==NULL) {
		(h->arr)[ind]=record;
		h->elementcount+=1;
		return h;
	}
	while(temp->next!=NULL) {
		if(strcmp(s[index],s[temp->index])==0) {
			temp->count+=1;
			free(record);
			return h;
		}
		temp=temp->next;
		count++;
	}
	if(strcmp(s[index],s[temp->index])==0) {
		temp->count+=1;
		free(record);
		return h;
	}
	h->insertioncost+=count;
	h->elementcount+=1;
	temp->next=record;
	return h;
}

int insertAll(Hash h, char** s) {
	for(int i=0;s[i]!=NULL;i++) {
		h = insert(h,s,i);
	}
	return h->insertioncost;
}

Rec lookup(Hash h, char* s, char** t) {
	int ind = hash(s,7507,5000);
	Rec temp = (h->arr)[ind];
	while(temp!=NULL) {
		h->queryingcost++;
		if(strcmp(s,t[temp->index])==0) {
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}

int lookupAll(Hash h, char** s, float m) {
	int size=0;
	for(int i=0;s[i]!=NULL;i++) {
		size++;
	}
	if(m<0||m>100) { return 0; }
	int x=(int)((m*size)/100.0);
	h->queryingcost=0;
	Rec temp;
	for(int i=0;i<x;i++) {
		temp = lookup(h,s[i],s);
	}
	return h->queryingcost;	
}
