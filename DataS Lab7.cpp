#include<stdio.h>
#include<stdlib.h>
#define INIT_SIZE 20
typedef int ElemType; 

typedef struct Node {
	int id;
	int weight;
	struct Node* next;
}Node;

typedef struct {
	int nVertices;
	Node** vertices;
}Graph;

void init(Graph &g,int nVertices){
	g.nVertices = nVertices;
	g.vertices = (Node**)malloc(sizeof(Node*)*nVertices);
	for(int i=0;i<g.nVertices;i++){
		g.vertices[i]=NULL;
	}
}

void addEdge(Graph &g,int u,int v){
	Node* n=(Node*)malloc(sizeof(Node));
	n->id=v;
	n->next=NULL;
	if(g.vertices[u]==NULL){
		g.vertices[u]=n;
	} else {
		Node *p=g.vertices[u];
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=n;
	}
}

void addBiEdge(Graph &g,int u,int v){
	addEdge(g,u,v);
	addEdge(g,v,u);
}

void dfsVisit(const Graph& g, int v, int* visited) {
	printf("%d ", v);
	visited[v] = 1;
	for (Node *p = g.vertices[v]; p != NULL; p = p->next) {
		if (!visited[p->id]) {
			dfsVisit(g, p->id, visited);
		}
	}
}

void dfs(const Graph& g, int v) {
	int i;
	int* visited = (int*)malloc(sizeof(int) * g.nVertices);
	for (i = 0; i < g.nVertices; i++) {
		visited[i] = 0;
	}
	dfsVisit(g, v, visited);
	for	(i = 0; i < g.nVertices; i++) {
		if (visited[i] == 0) {
			dfsVisit(g, i, visited);
		}
	}
	printf("\n");
}

typedef struct {
	ElemType* elems;
	int front;
	int rear;
	int size;
} Queue;

void init(Queue& q) {
	q.elems = (ElemType *)malloc(sizeof(ElemType) * INIT_SIZE);
	q.front = 0;
	q.rear = 0;
	q.size = INIT_SIZE;
}

int enq(Queue& q, ElemType e) {
	int newRear = (q.rear + 1) % q.size;
	if (newRear == q.front) {
		return 0;
	} else {
		q.elems[q.rear] = e;
		q.rear = newRear;
		return 1;
	}
}

ElemType deq(Queue& q) {
	ElemType e = q.elems[q.front];
	q.front = (q.front + 1) % q.size;
	return e;
}	

int isEmpty(Queue& q) {
	return q.front == q.rear;
}

void bfsVisit(const Graph& g, int v, int* visited) {
	Queue q;
	init(q);
	enq(q, v);
	while (!isEmpty(q)) {
		int n = deq(q);
		if (!visited[n]) {
			printf("%d ", n);
			visited[n] = 1;
		}
		for (Node *p = g.vertices[n]; p != NULL; p = p->next) {
			if (!visited[p->id]) {
				enq(q, p->id);
			}
		}
	}
}


void bfs(const Graph& g, int v) {
	int i;
	int* visited = (int*)malloc(sizeof(int) * g.nVertices);
	for (i = 0; i < g.nVertices; i++) {
		visited[i] = 0;
	}
	bfsVisit(g, v, visited);
	for (i = 0; i < g.nVertices; i++) {
		if (visited[i] == 0) {
			bfsVisit(g, i, visited);
		}
	}
	printf("\n");
}

int main() {
	Graph g;
	init(g, 8);
	addBiEdge(g, 0, 1);
	addBiEdge(g, 1, 3);
	addBiEdge(g, 1, 4);
	addBiEdge(g, 3, 7);
	addBiEdge(g, 0, 2);
	addBiEdge(g, 2, 5);
	addBiEdge(g, 2, 6);
	addBiEdge(g, 5, 6);
	printf("图的深度优先遍历：  ");
	dfs(g, 0);
	printf("图的广度优先遍历：  ");
	bfs(g, 0);
}

