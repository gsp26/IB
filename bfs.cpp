#include<iostream>

using namespace std;

class DoubleList
{
    public:
    int data;
    DoubleList * next;
    DoubleList * prev;
    DoubleList(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

class queue
{
    DoubleList * node;
    DoubleList *back;
    int size;
    public:
    queue(int d) //constructor intialize with a element
    {
        node = new DoubleList(d);
        back = node;
        size = 1;
    }
    queue()
    {
        node = NULL;
        back = NULL;
        size = 0;
    }
    void push(int d)
    {
        if(node == NULL) //first node
        {
            node = new DoubleList(d);
            back = node;
        }
        else
        {
            DoubleList* temp = new DoubleList(d);
            temp->next = node;
            node->prev = temp;
            node = temp;
        }
            size++;
    }
    int pop()
    {
        if(back == NULL)
            return -1; //queue is empty
        DoubleList* temp = back->prev;
        int d = back->data;
        delete back;
        back = temp;
        if(temp != NULL)
            temp->next = NULL;
        size--;
        if(size ==0 )
            node = NULL;
        return d;
    }
    int getSize()
    {
        return size;
    }
    bool empty(){return size == 0;}
    void printQueue()
    {
        DoubleList * temp = node;
        cout << "Queue elements :\n" << endl;
        while( temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};
class AdjListNode
{
	public:
	int dest;
	AdjListNode * next;
	AdjListNode(int d)
	{
		dest = d;
		next = NULL;
	}
};

class AdjList
{
	public:
	AdjListNode * head;
};

class Graph
{
	int v;
	AdjList * array;
	public:
	Graph(int n)
	{
		v = n;
		array = new AdjList[v];
		for(int i=0;i<v;i++)
			array[i].head = NULL;
	}
	void addEdge(int src,int dest);
	void bfs(int src);
	void dfs(int src);
	void dfsUtil(int src,bool visited[]);
};
void Graph::addEdge(int src, int dest)
{
	AdjListNode * newNode = new AdjListNode(dest);
	newNode->next = array[src].head;
	array[src].head = newNode;
}

void Graph::dfs(int src)
{

	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
		visited[i] = false;

	dfsUtil(src,visited);
}

void Graph::dfsUtil(int src, bool visited[])
{
	visited[src] = true;

	cout << src <<  " ";

	AdjListNode * itr = array[src].head;
	while(itr != NULL)
	{
		if(!visited[itr->dest])
			dfsUtil(itr->dest,visited);
		itr = itr->next;
	}
}

void Graph::bfs(int src)
{
    bool *visited = new bool[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    //queuq for bfs
    queue qu;

    visited[src] = true;
    qu.push(src);


    AdjListNode * temp;
    while(!qu.empty())
    {
        int s = qu.pop();
        cout << s<< " ";
        temp = array[s].head;
        while(temp != NULL)
        {
            if(!visited[temp->dest])
            {
                visited[temp->dest] = true;
                qu.push(temp->dest);
            }
            temp = temp->next;
        }
    }
}


int main()
{
	cout << " BFS using classes >>>> " << endl;
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);

    g.bfs(2);
    cout << "\n\n";
    g.dfs(2);
    queue qu;
    cout << "\n\n";
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.printQueue();

    cout << "\n POP queue : " <<  qu.pop() << endl;
    cout << "\n POP queue : " <<  qu.pop() << endl;
    cout << "\n POP queue : " <<  qu.pop() << endl;
    cout << "\n POP queue : " <<  qu.pop() << endl;
    cout << "\n is Queue empty : " << qu.empty() << " : size " << qu.getSize() << endl;
    qu.printQueue();


	return 0;

}
