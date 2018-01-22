#include "multiq.h"
#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
MultiQ createMQ(int num) {

	MultiQ q = (MultiQ) malloc(sizeof(struct multiq));
	q->arr = (Queue*)malloc(num*sizeof(Queue));
	for(int i=0;i<num;i++) {

		q->arr[i]=newQ();
	}
	q->start=&(q->arr[0]);
	q->end=&(q->arr[num-1]);
	return q;
}

MultiQ addMQ(MultiQ mq, Task t) {
	mq->arr[t->priority-1] = addQ(mq->arr[t->priority-1] , t);
	return mq;
}

Task nextMQ(MultiQ mq) {
	if(mq->arr[0]==NULL) {
		return NULL;
	}
	Task t = NULL;
	int count=0;
	Queue * x = mq->start;
	for(;x!=mq->end;x=&(mq->arr[++count])) {
		if((*x)->head!=NULL) {
			t = front(*x);
		}
	}
	if((*x)->head!=NULL) {
		t=front(*x);
	}
	return t;
}

MultiQ delNextMQ(MultiQ mq) {
	if(mq->start==NULL) {
		return mq;
	}
	Queue* x = mq->start;

	int count=0;
	int flag = -1;
	for(;x!=mq->end;x=&(mq->arr[++count])) {
		if((*x)->head!=NULL) {

			flag=count;
		}
	}
	if((*x)->head!=NULL) {

		flag=count;
	}
	if(flag==-1) {
		return mq;
	}
	mq->arr[flag] = delQ(mq->arr[flag]);
	return mq;
}

Boolean isEmptyMQ(MultiQ mq) {
	int count=0;
	Queue * q=mq->start;
	for(;q!=mq->end;q=&(mq->arr[++count])) {
		if((*q)->head!=NULL) {
			return False;
		}
	}
	if((*q)->head!=NULL) {
		return False;
	}
	return True;
}

int sizeMQ(MultiQ mq) {
	int count=0;
	int count1=0;
	Queue * q=mq->start;
	for(;q!=mq->end;q=&(mq->arr[++count])) {
		count1+=lengthQ(*q);
	}
	count1+=lengthQ(*q);
	return count1;
}

int sizeMQbyPriority(MultiQ mq, Priority p) {
	return lengthQ(mq->arr[p-1]);
}

Queue getQueueFromMQ(MultiQ mq, Priority p) {
	return mq->arr[p-1];
}

void print(MultiQ mq) {
	Queue * q=mq->start;
	int count=0;
	for(;q!=mq->end;q=&(mq->arr[++count])) {
		trav((*q));
	}
	trav((*q));
	printf("\n");
}

MultiQ loadData(MultiQ q, FILE* f) {
	struct timeval t1, t2;
	double elapsedTime;
	int tid,p;
	gettimeofday(&t1, NULL);
	int count=0;
	while(fscanf(f,"%d,%d",&tid,&p)!=EOF) {
		q = addMQ(q, abc(tid,p));
		count++;
	}
 	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Avg time is %f ms.\n", elapsedTime/count);
	return q;
}

MultiQ testDel(MultiQ q, int num) {
	struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);
	for(int i=0;i<num;i++) {
		q = delNextMQ(q);
	}
 	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Avg time is %f ms.\n", elapsedTime/num);
	return q;
}
