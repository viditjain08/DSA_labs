#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ex1.h"
int hash(char* s,int base,int size) {
	int x=0;
	for(int i=0;s[i]!='\0';i++) {
		x+=(int)s[i];
	}
	return (x%base)%size;
}


int colcount(char** s,int base,int size) {
	int arr[size];
	for(int i=0;i<size;i++) {
		arr[i]=-1;
	}
	
	for(int i=0;s[i]!=NULL;i++) {
		arr[hash(s[i],base,size)]++;
	}
	int x=0;
	for(int i=0;i<size;i++) {
		if(arr[i]!=-1) {x+=arr[i];}
	}
	return x;
}

char** parse(FILE* fp) {
	char **s = malloc(10 * sizeof(char *));
	int count=0;
	char *temp = (char*)malloc(sizeof(char)*30);
	while(fscanf(fp, "%s",temp)!=-1) {
		if(count==0) {
			temp=temp+3;
		}
		int i=0;
		int flag=0;
		for(;temp[i]!='\0';) {
			if(isalpha(temp[i]) == 0) {
				flag=1;
				break;
			}
			i++;
		}

		if(flag==0) {
			s[count] = (char *)malloc(i+1);
			strcpy(s[count],temp);
			count++;

			if(count%10==0) {
				s = (char **)realloc(s, sizeof(char*)*(count+10));
			}
		}

	}
	printf("Number of words-%d\n",count);
	return s;
}

int isPrime(int x) {
	for(int i=2;i<x;i++) {
		if(x%i==0) {
			return 0;
		}
	}
	return 1;
}
void profiling(char** book) {
	int tsize = 5000;
	int y=0;
	int arr1[18],arr2[18],arr3[18];
	for(int i=0;i<3;i++,tsize*=10) {
		int count=0;
		int x = tsize;
		for(int j=1.5*x;j<2*x&&count!=3;j++) {
			if(isPrime(j)) {
				count++;
				arr1[y]=j;
				arr2[y]=tsize;
				arr3[y++]=colcount(book,j,tsize);
				printf("Collision count of %d %d = %d\n",j,tsize,colcount(book,j,tsize));
			}
		}
		count=0;
		x = 1000*tsize;
		for(int j=1.5*x;count!=3;j++) {
			if(isPrime(j)) {
				count++;
				arr1[y]=j;
				arr2[y]=tsize;
				arr3[y++]=colcount(book,j,tsize);
				printf("Collision count of %d %d = %d\n",j,tsize,colcount(book,j,tsize));
			}
		}
	}
	int small=0;
	for(int i=0;i<18;i++) {
		if(arr3[small]>arr3[i]) {
			small=i;
		}
	}
	printf("Best Collision count of %d %d = %d\n",arr1[small],arr2[small],arr3[small]);
}

