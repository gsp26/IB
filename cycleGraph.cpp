#include<iostream>

using namespace std;


struct Edge
{
    int src,dest;
};

struct Graph
{
    int v, e;
    struct Edge * edge;
};

struct Graph * createGraph(int v,int e)
{
    struct Graph * graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->v = v;
    graph->e = e;

    graph->edge = (struct Edge*)malloc(graph->e * sizeof(struct Edge));

    return graph;
}

int find(int parent[],int i)
{
    if(parent[i] == -1)
        return i;
    return find(parent,parent[i]);
}

void Union(int parent[],int x, int y)
{
    int xset = find(parent,x);
    int yset = find(parent,y);

    parent[xset] = yset;
}

int isCycle(struct Graph * graph)
{
    int * parent = (int*)malloc(graph->v*sizeof(int));
    for(int i=0;i<graph->v;i++)
        parent[i] = -1;

    for(int i=0;i<graph->e;i++)
    {
        int x = find(parent,graph->edge[i].src);
        int y = find(parent,graph->edge[i].dest);

        if(x==y)
            return 1;

        Union(parent,x,y);
    }

    return 0;
}

int main()
{
    int v =3,e=3;

    struct Graph * graph = createGraph(v,e);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    graph->edge[2].src = 2;
    graph->edge[2].dest = 0;

    if(isCycle(graph))
        cout << "Graph contains cycle" << endl;
    else
        cout << "Graph doesn't contain cycle" << endl;

    return 0;
}


