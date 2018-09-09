#include<iostream>

using namespace std;


class List
{
    public:
    int data;
    List * next;
    List(int d)
    {
        data = d;
        next = NULL;
    }
};
class stack
{
    List * node;
    List * head;
    int size;
    public:
    stack(int d)
    {
        node = new List(d);
        head = node;
    }
    stack()
    {
        node = NULL;
        head = NULL;
    }
    void push(int d)
    {
        if(head == NULL) //first element
        {
            node = new List(d);
            head = node;
        }
        else
        {
            List * temp = new List(d);
            temp->next = head;
            head = temp;
        }
        size++;
    }
    int pop()
    {
        if(head == NULL)
            return -1;

        int res = head->data;
        List *temp = head;
        head = head->next;
        delete temp;
        return res;
    }
    int getSize(){return size;}
    bool empty(){return size == 0;}
    void printStack()
    {
        List * temp = head;
        cout << "Stack elements are :- " << endl;
        while(temp != NULL)
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
    void addEdge( int src, int dest);
    void fillOrder(int v, bool visited[],stack& st);
    void DFUtil(int v, bool visited[]);
    void printSCCs();
    Graph getTranspose();
};

void Graph::addEdge(int src,int dest)
{
    AdjListNode * newNode = new AdjListNode(dest);
    newNode->next = array[src].head;
    array[src].head = newNode;
}

void Graph::DFUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v <<  " ";

    AdjListNode * temp = array[v].head;
    while(temp != NULL)
    {
        if(!visited[temp->dest])
            DFUtil(temp->dest,visited);
        temp =temp->next;
    }
}

Graph Graph::getTranspose()
{
    Graph g(v);
    for(int i=0;i<v;i++)
    {
        AdjListNode * temp = array[i].head;
        //reverse the edges
        while(temp != NULL)
        {
            g.addEdge(temp->dest,i);
            temp = temp->next;
        }
    }
    return g;
};

void Graph::fillOrder(int v, bool visited[],stack& st)
{
    visited[v] = true;

    AdjListNode * temp = array[v].head;

    while(temp != NULL)
    {
        if(!visited[temp->dest])
            fillOrder(temp->dest,visited,st);
        temp = temp->next;
    }
     st.push(v);
}

void Graph::printSCCs()
{
    stack st;
    bool *visited = new bool[v];
    for(int i=0;i<v;i++)
        visited[i] = false;

    //fill vertices in stack according to their finishing times
    for(int i=0;i<v;i++)
        if(!visited[i])
            fillOrder(i,visited,st);

    Graph g = getTranspose();

    //mark all the vertices as not visited
    for(int i=0;i<v;i++)
        visited[i] = false;

    //now process all the vertices in order defined by stack
    while(!st.empty())
    {
        int v= st.pop();
        if(!visited[v])
        {
            g.DFUtil(v,visited);
            cout << endl;
        }
    }
}


int main()
{
    cout << "kosraju's strongly connected components >>>> " << endl;

    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);

    cout << "Stringly connected components in the graph are : " << endl;

    g.printSCCs();

    return 0;
};
