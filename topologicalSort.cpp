#include<iostream>
#include<list>
#include<stack>

using namespace std;

class Graph
{
	int v;
	list<int> * adj;
	void topologicalSortUtil(int v, bool visited[],stack<int> &st);
	public:
	Graph(int v);
	void addEdge(int v,int w);
	void topologicalSort();
};

Graph::Graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[],stack<int>&st)
{
	visited[v] = true;
	for(list<int>::iterator it = adj[v].begin();it != adj[v].end();it++)
		if(!visited[*it])
			topologicalSortUtil(*it,visited,st);

	st.push(v);
}

void Graph::topologicalSort()
{
	stack<int> st;
	bool *visited = new bool[v];
	
	for(int i=0;i<v;i++)
		visited[i] = false;

	for(int i=0;i<v;i++)
		if(visited[i] == false)
			topologicalSortUtil(i,visited,st);

	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
}

int main()
{
	Graph g(6);
	g.addEdge(5,2);
	g.addEdge(5,0);
	g.addEdge(4,0);
	g.addEdge(4,1);
	g.addEdge(2,3);
	g.addEdge(3,1);

	cout << "Following is Topological sort of the given graph "<<endl;

	g.topologicalSort();

	return 0;
}
