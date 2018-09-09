#include<iostream>
#include<limits.h>
#include<stdlib.h>

using namespace std;

//A structure to represnt a node in Adjacency List
struct AdjListNode
{
	int dest;
	int weight;
	struct  AdjListNode* next;
};


//A structure to represent an adjacency list
struct AdjList
{
	struct AdjListNode* head;
};

//A structure to represent graph. Agraph is an Array of adjacency lists
//size of array will be v (number of vertices in graph)
struct Graph
{
	int v;
	struct AdjList* array;
};

//A utility function to create a new Adjaceny list node 
struct AdjListNode* newAdjListNode(int dest, int weight)
{
	struct AdjListNode * newNode = new AdjListNode;
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

//A utility function that creates Graph of v vertices
struct Graph * createGraph(int v)
{
	struct Graph * g = new Graph;
	g->v = v;
	g->array = new AdjList[v];
	for(int i=0;i<v;i++)
		g->array[i].head = NULL;
	return g;
}


//adds an Edge to an undirected Graph
void addEdge(struct Graph *g,int src, int dest,int weight)
{
	struct AdjListNode * newNode = newAdjListNode(dest,weight);
	newNode->next = g->array[src].head;
	g->array[src].head = newNode;

	//since graph is undirected , add an edge from dest to source also
	newNode = newAdjListNode(src,weight);
	newNode->next = g->array[dest].head;
	g->array[dest].head = newNode;
}

//structure to represent min heap node 
struct MinHeapNode
{
	int v;
	int dist;
};

//structure to represent min heap
struct MinHeap
{
	int size; //number of heap nodes present currently
	int capacity;// capacity of min heap 
	int *pos; // this is needed for decrease key
	struct MinHeapNode **array;
};

//A utility function to create a min heap Node
struct MinHeapNode * newMinHeapNode(int v, int dist)
{
	struct MinHeapNode * minHeapNode = new MinHeapNode;
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

//A utlitiy function to create a min Heap
struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap = new MinHeap;
	minHeap->pos = new int[capacity];
	minHeap->size = 0;
	minHeap->array = new MinHeapNode*[capacity];
	return minHeap;
}

//a utility function to swap to nodes of a min heap
void swapMinHeapNode(struct MinHeapNode **a,struct MinHeapNode ** b)
{
	struct MinHeapNode * t= *a;
	*a = *b;
	*b = t;
}

//a Standard function to heapify at given idx 
//This function also updates position of nodes when they are swapped
//position is needed for decrease key
void minHeapify(struct MinHeap * minHeap, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 *idx +1;
	right = 2 * idx +2;

	if(left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
		smallest = left;

	if(right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
		smallest = right;

	if(smallest != idx)
	{
		//The node to be swapped in min heap
		MinHeapNode * smallestNode = minHeap->array[smallest];
		MinHeapNode * idxNode = minHeap->array[idx];

		//swap positions 
		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[idx]);

		minHeapify(minHeap,smallest);
	}
}

//a utility function to check if minHeap is empty
int isEmpty(struct MinHeap * minHeap)
{
	return minHeap->size == 0;
}

//standard function to extract minimum node from heap
struct MinHeapNode * extractMin(struct MinHeap * minHeap)
{
	if(isEmpty(minHeap))
		return NULL;

	struct MinHeapNode * root = minHeap->array[0];
	
	//replace root node with last node 
	struct MinHeapNode * lastNode = minHeap->array[minHeap->size-1];
	minHeap->array[0] = lastNode;

	//update position of last node 
	minHeap->pos[lastNode->v] = 0;
	minHeap->pos[root->v] = 0;

	//reduce size
	--minHeap->size;
	minHeapify(minHeap,0);

	return root;
}

//Function to decrease dist value of a given vertex v. This function uses 
//pos[] of minHeap to get the current index of node in minHeap
void decreaseKey(struct MinHeap * minHeap, int v, int dist)
{
	//get the index of the v in heap array;
	int i= minHeap->pos[v];
	//get the node and update its value
	minHeap->array[i]->dist = dist;
	
	//travel up while the complete tree is not heapified 
	//travel is o(logn) loop
	while(i && minHeap->array[i]->dist < minHeap->array[(i-1)/2]->dist)
	{
		//swap this node with its parent
		minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
		minHeap->pos[minHeap->array[(i-1)/2]->v] = i;

		swapMinHeapNode(&minHeap->array[i],&minHeap->array[(i-1)/2]);

		// move to parent
		i = (i-1)/2;
	}
}

//a utility function to check if gievn vertex v is in heap or not
bool isInMinHeap(struct MinHeap * minHeap,int v)
{
	if(minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

// A utility function to print the solution
void printArr(int dist[], int n)
{
	cout << "Vertex Distance form souce " << endl;
	for(int i=0;i<n;i++)
		cout << i << "  ---  " << dist[i] << endl;
}

void dijkstra(struct Graph* g, int src)
{
	int v= g->v;
	int dist[v];

	//minHeap represents set E
	struct MinHeap * minHeap = createMinHeap(v);

	//intialise min heap with all vertices and dist value of all vertices
	for(int i=0;i<v;i++)
	{
		dist[i] = INT_MAX;
		minHeap->array[i] = newMinHeapNode(i,dist[i]);
		minHeap->pos[i] = i;
	}

	//make dist vlaue of src as 0 so that it is extracted first
	minHeap->array[src] = newMinHeapNode(src,dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	decreaseKey(minHeap,src,dist[src]);

	//inital size of minHeap is v;
	minHeap->size = v;

	//in the following loop, min heap contains all nodes 
	//whose shortes distance is not yet finalised.
	while(!isEmpty(minHeap))
	{
		//Extract the vertex of the minimum distance value
		struct MinHeapNode * minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v;


		//trvaerse through the adjacent vertices of u ( the extracted vertex)
		//and update there dis value
		struct AdjListNode * pCrwal  = g->array[u].head;
		while(pCrwal != NULL)
		{
			int v = pCrwal->dest;

			//if the shortest ditance to v is not finalised yet, and distance to v
			//through u is less than its previously calculated distance 
			if(isInMinHeap(minHeap,v) && dist[u] != INT_MAX && pCrwal->weight + dist[u]< dist[v])
			{
				dist[v] = dist[u] + pCrwal->weight;

				//update the distance value in  min heap also

				decreaseKey(minHeap,v,dist[v]);
			}
			pCrwal = pCrwal->next;
		}
	}
	printArr(dist,v);
}


int main()
{
	int v= 9;
	struct Graph * g = createGraph(v);

	addEdge(g,0,1,4);
	addEdge(g,0,7,8);
	addEdge(g,1,2,8);
	addEdge(g,1,7,11);
	addEdge(g,2,3,7);
	addEdge(g,2,8,2);
	addEdge(g,2,5,4);
	addEdge(g,3,4,9);
	addEdge(g,3,5,14);
	addEdge(g,4,5,10);
	addEdge(g,5,6,2);
	addEdge(g,6,7,1);
	addEdge(g,6,8,6);
	addEdge(g,7,8,7);

	dijkstra(g,0);

	return 0;
}





