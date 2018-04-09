#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include<string.h>
typedef struct currentset* currentSet;
typedef struct iter* Iterator;
typedef struct node* Node;
struct currentset {
	Node n;
	currentSet next;
};

struct node {
	char name[300];
	Iterator i;
};
struct iter {
	int total_size;
	int current_size;
	Node start;
	Node current;
};

int hasMoreElements(Iterator it) {
	if(it==NULL) { return 0;}
	if(it->current_size!=0) {
		return 1;
	}
	it->current=it->start;
	it->current_size=it->total_size;
	return 0;
}

Node getNextElement(Iterator it) {
	if(it->total_size==0) {
		return NULL;
	}
	Node n;
	if(it->current_size!=0) {
		n = it->current;
		it->current_size--;
		it->current = (it->current)+1;
	}
	return n;
}

Node create(Node n, char* name) {
	strcpy(n->name,name);

	int count=0;
	struct stat path_stat;
    stat(name, &path_stat);
	printf("-%s\n",name);
    if(!S_ISDIR(path_stat.st_mode)) {
			n->i=NULL;
			return n;
	}
	
	DIR * dirp;
	struct dirent * entry;
	dirp = opendir(name);
	while ((entry = readdir(dirp)) != NULL) {
		if ( !strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..") ) { } else {count++;}
	}
	closedir(dirp);
	
	n->i = (Iterator)malloc(sizeof(struct iter));
	n->i->start = (Node)malloc(count*sizeof(struct node));
	n->i->total_size = count;
	n->i->current_size = count;
	n->i->current = n->i->start;
	Iterator temp = n->i;
	
	dirp = opendir(name);
	
	while((entry = readdir(dirp)) != NULL) {
		if ( !strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..") ) { }
		else {
			Node n1 = getNextElement(temp);
			printf("%d",temp->current_size);
			char x[300];
			strcpy(x,name);
			strcat(x,"/");
			strcat(x,entry->d_name);
			n1 = create(n1,x);
		}
	}
	closedir(dirp);
	
	return n;
}



Node selectNextNode(currentSet s) {
	return s->n;
}
Iterator identifyMoreNodes(Node n) {
	return n->i;
}
currentSet addMoreNodes(currentSet s, Iterator i) {

	if(i==NULL || hasMoreElements(i)==0) {
		currentSet x = s;
		s=s->next;
		free(x);
		if(s==NULL) {
			return s;
		}
		Iterator new = identifyMoreNodes(s->n);
		s = addMoreNodes(s,new);
	} else {
		currentSet temp = (currentSet)malloc(sizeof(struct currentset));
		Node n = getNextElement(i);
		temp->n = n;
		temp->next = s;
		s = temp;
	}
	return s;
}

void visitNode(Node n) {
	char *ret;
	ret = strrchr(n->name, '/');
	int i=0;
	while(n->name[i]!='\0') {
		if(n->name[i]=='/') {
			printf("   ");
		}
		i++;
	}
	printf("-%s\n",ret+1);
	int x = hasMoreElements(n->i);
}

void traverse(Node n1) {
	printf("\nDepth First Traversal\n");
	currentSet s = (currentSet)malloc(sizeof(struct currentset));
	s->n = n1;
	Node n;
	s->next = NULL;
	int i=0;
	while(s!=NULL) {
		n = selectNextNode(s);

		visitNode(n);

		s = addMoreNodes(s, identifyMoreNodes(n));

	} 
}
int main() {

    struct stat path_stat;
    stat("~/dev", &path_stat);
	Node n=(Node)malloc(sizeof(struct node));
	n = create(n, "/home/viditjain08/Music/vidit");
	printf("\n");
	traverse(n);
    /*DIR *dir;
    struct dirent *dp;
    char * file_name;
    dir = opendir("./ex3.c");
    while ((dp=readdir(dir)) != NULL) {
        printf("debug: %s\n", dp->d_name);
        if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") )
        {
            // do nothing (straight logic)
        } else {
            file_name = dp->d_name; // use it
            printf("file_name: \"%s\"\n",file_name);
        }
    }
    closedir(dir);
	*/
	return 0;
}
