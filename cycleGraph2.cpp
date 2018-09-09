#include<iostream>

using namespace std;

struct Edge
{
    int src,dest;
};

struct Graph
{
    int v;
    int e;
    struct Edge * edge;
};

struct Graph * createGraph(int v,int e)
{
    struct Graph * graph = (struct Graph *) malloc(sizeof(struct Graph));
    graph->v = v;
    graph->e = e;

    graph->edge = (struct Edge*)malloc(graph->e * sizeof(struct Edge));

    return graph;
}

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    //find root and make root as parent of i (path compression)
    if(subsets[i].parent != i )
        subsets[i].parent = find(subsets,subsets[i].parent);

    return subsets[i].parent;
}

void Union(subset subsets[],int x, int y)
{
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);

    //attach smaller rank tree under root of higer rank tree
    //union by rank
    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    //if ranks are same then make one as root and increment its rank by 1
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


int iscycle(struct Graph * graph)
{
    int v = graph->v;
    int e = graph->e;

    struct subset * subsets = (struct subset*)malloc(v*sizeof(struct subset));
    for(int i=0;i<v;i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    for(int i=0;i<e;i++)
    {
        int x = find(subsets,graph->edge[i].src);
        int y = find(subsets,graph->edge[i].dest);

        if(x==y)
            return 1;

        Union(subsets,x,y);
    }

    return 0;
}


int main()
{
    int v=3,e=3;
    struct Graph * graph = createGraph(v,e);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;


    if(iscycle(graph))
        cout << "Graph contains Cycle " << endl;
    else
        cout << "Graph doesn't contain Cycle " << endl;

    return 0;
}

