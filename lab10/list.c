#include<stdio.h>
#include<stdlib.h>

typedef struct vertex* Vertex;
typedef struct graph* Graph;
typedef struct node* Node;
struct vertex {
	int value;
	int visited;
};
struct node {
	int x;
	Node next;
};
struct graph {
	Vertex vertices;
	Node* list;
	int v_count;
};

int func(Vertex a) {
	return a->value;
}
Graph createGraph(int numV) {
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->list = (Node*)malloc(sizeof(Node)*numV);
	g->vertices = (Vertex)malloc(sizeof(struct vertex)*numV);
	g->v_count = numV;
	for(int i=0;i<numV;i++) {
		(g->list)[i] = NULL;
		(g->vertices)[i].value = i;
		(g->vertices)[i].visited = 0;
	}
	return g;
}

Node getAdjacent(Graph G, Vertex v) {
	return (G->list)[func(v)];
}

Graph addEdge(Graph G, Vertex v, Vertex vAdj) {
	int i=func(v);
	int j=func(vAdj);
	if((G->list)[i]==NULL) {
		(G->list)[i] = (Node)malloc(sizeof(struct node));
		(G->list)[i]->x = j;
		(G->list)[i]->next = NULL;
	} else {
		Node temp;
		for(temp=(G->list)[i];temp->next!=NULL;temp=temp->next) {
			if(temp->x==j) {
				break;
			}
		}
		if(temp->next==NULL && temp->x!=j) {
			temp->next= (Node)malloc(sizeof(struct node));
			temp=temp->next;
			temp->x = j;
			temp->next=NULL;
		}
	}
	return G;
}

int degree(Graph G, Vertex v) {
	int count=0;
	for(int i=0;i<G->v_count;i++) {
		Node temp=(G->list)[i];
		while(temp!=NULL) {
			if(i==func(v)) {
				count++;
			}
			if(temp->x==func(v)) {
				count++;
			}
			temp=temp->next;
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
		if((g->list)[i]==NULL) {
			printf("%d\t", i);
		} else {
			printf("%d\t", ((g->list)[i])->x);
		}
	}
	printf("%d\n\n",degree(g,&(g->vertices)[2]));
	bfs(g);

	return 0;
}
