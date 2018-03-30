#include<stdio.h>
typedef struct rec* Rec;
struct rec {
	int index;
	int count;
	Rec next;
};

struct hash {
	Rec* arr;
	int elementcount;
	int insertioncost;
	int queryingcost;
};
typedef struct hash* Hash;
Hash create(int);
Hash insert(Hash h,char** s,int index);
int insertAll(Hash h, char** s);
Rec lookup(Hash h, char* s, char** t);
int lookupAll(Hash h, char** s, float m);
