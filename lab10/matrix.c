#include<stdio.h>
#include<stdlib.h>

typedef struct vertex* Vertex;
typedef struct graph* Graph;
typedef struct node* Node;
struct vertex {
	int value;
	int visited;
};
struct graph {
	Vertex vertices;
	int** matrix;
	int v_count;
};

struct node {
	int x;
	Node next;
};

int func(Vertex a) {
	return a->value;
}
Graph createGraph(int numV) {
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->matrix = (int**)malloc(sizeof(int*)*numV);
	g->vertices = (Vertex)malloc(sizeof(struct vertex)*numV);
	g->v_count = numV;
	for(int i=0;i<numV;i++) {
		(g->matrix)[i] = (int*)malloc(sizeof(int)*numV);
		(g->vertices)[i].value = i;
		(g->vertices)[i].visited = 0;
		for(int j=0;j<numV;j++) {
			(g->matrix)[i][j]=0;
		}
	}
	return g;
}

Node getAdjacent(Graph G, Vertex v) {
	Node n=NULL, temp;
	for(int i=0;i<G->v_count;i++) {
		if((G->matrix)[func(v)][i]!=0) {
			if(n==NULL) {
				n = (Node)malloc(sizeof(struct node));
				n->x = i;
				temp = n;
				temp->next=NULL;
			} else {
				temp->next = (Node)malloc(sizeof(struct node));
				temp = temp->next;
				temp->x = i;
				temp->next = NULL;
			}
		}
	}
	return n;
}

Graph addEdge(Graph G, Vertex v, Vertex vAdj) {
	int i=func(v);
	int j=func(vAdj);
	(G->matrix)[i][j]=1;
	return G;
}

int degree(Graph G, Vertex v) {
	int count=0;
	for(int i=0;i<G->v_count;i++) {
		if((G->matrix)[func(v)][i]!=0) {
			count++;
		}
		if((G->matrix)[i][func(v)]!=0) {
			count++;
		}
	}
	return count;
}

void bfs(Graph g) {
	Vertex v = g->vertices;
	printf("%d\t",v->value);
	v->visited = 1;
	int count=1;
	Node n = getAdjacent(g,v);
	while(count!=g->v_count && n!=NULL) {
		Node temp = n;
		n = n->next;
		Vertex v2 = (g->vertices)+(temp->x);
		if(v2->visited==0) {
			printf("%d\t",v2->value);
			v2->visited = 1;
			count++;
			Node t = getAdjacent(g,v2);
			if(n==NULL) { n=t; }
			else {
				Node t2 = n;
				for(;t2->next!=NULL;t2=t2->next);
				t2->next=t;
			}
		}
	}
}
int main() {
	Graph g = createGraph(5);
	g = addEdge(g,&(g->vertices)[0],&(g->vertices)[1]);
	g = addEdge(g,&(g->vertices)[1],&(g->vertices)[3]);
	g = addEdge(g,&(g->vertices)[1],&(g->vertices)[4]);
	g = addEdge(g,&(g->vertices)[4],&(g->vertices)[3]);
	g = addEdge(g,&(g->vertices)[4],&(g->vertices)[2]);
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			printf("%d\t",(g->matrix)[i][j]);
		}
		printf("\n");
	}
	printf("%d\n\n",degree(g,&(g->vertices)[2]));
	Node n = getAdjacent(g, (g->vertices)+2);
	bfs(g);
	return 0;
}
