#include<iostream>

using namespace std;

struct AdjListNode
{
	int dest;
	//int weight;
	struct AdjListNode* next;
};

struct AdjList
{
	struct AdjListNode * head;
};

struct Graph
{
	int v;
	struct AdjList * array;
};

struct AdjListNode* newAdjListNode(int  dest /*,int weight*/)
{
	struct AdjListNode * newNode  = new AdjListNode;
	newNode->dest = dest;
	//newNode->weight = weight;
	newNode->next  = NULL;
    return newNode;
}

struct Graph * createGraph(int v)
{
	struct Graph * g = new Graph;
	g->v = v;
	g->array = new AdjList[v];

	for(int i=0;i<v;i++)
		g->array[i].head = NULL;
	return g;
}
	

void addEdge(struct Graph *g, int src, int dest/*, int weight*/)
{
	struct AdjListNode * newNode = newAdjListNode(dest/*,weight*/);
	newNode->next = g->array[src].head;
	g->array[src].head = newNode;
}

void DFSUtil(struct Graph *g, int src,bool visited[])
{
	visited[src] = true;
	cout << src << " ";

	//recurr for all the verticess adjacent to this vertex
	AdjListNode * itr = g->array[src].head;
	while(itr != NULL)
	{
		if(!visited[itr->dest])
			DFSUtil(g,itr->dest,visited);
		itr= itr->next;
	}
}

void DFS(struct Graph * g, int src)
{
	int v = g->v;
	bool *visited = new bool[v];

	for(int i=0;i<v;i++)
		visited[i] = false;

	DFSUtil(g,src,visited);
}

	


int main()
{
	cout << " DFS of a graph >>>>> " << endl;
	struct Graph * g = createGraph(4);
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,1,2);
	addEdge(g,2,0);
	addEdge(g,2,3);
	addEdge(g,3,3);

	DFS(g,2);

	return 0;
}
