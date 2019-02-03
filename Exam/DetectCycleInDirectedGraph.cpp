#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph
{
public:
	Graph(int vertices, int edges)
	{
		this->v = vertices + 1;
		this->e = edges;
		this->graph = new list<pair<int, int>>[this->v];
	}

	void AddEdge(int u, int v, int w)
	{
		this->graph[u].push_back(make_pair(v, w));
	}

	bool IsCyclicUtil(int v, vector<bool> &visited, vector<bool> &recursionStack)
	{
		if (visited[v] == false)
		{
			visited[v] = true;
			recursionStack[v] = true;
			list<pair<int, int>>::iterator i;
			for (i = this->graph[v].begin(); i != this->graph[v].end(); ++i)
			{
				if (visited[i->first] == false && IsCyclicUtil(i->first, visited, recursionStack) == true)
				{
					return true;
				}
				else if (recursionStack[i->first] == true)
				{
					return true;
				}
			}
		}
		recursionStack[v] = false; // remove the vertex from recursion stack
		return false;
	}

	bool IsCyclic()
	{
		// Mark all the vertices as not visited and not part of recursion 
		// stack 
		vector<bool>visited(this->v, false);
		vector<bool> recursionStack(this->v, false);

		for (int i = 0; i < this->v; i++)
		{
			if (visited[i] == false)
			{
				if (IsCyclicUtil(i, visited, recursionStack) == true)
				{
					return true;
				}
			}
		}
		return false;
	}

	~Graph()
	{
		delete[] graph;
	}

private:
	int v;
	int e;
	list<pair<int, int>> *graph;
};

int main()
{
	int n;
	cin >> n;

	int vertices;
	int edges;
	for (int i = 0; i < n; i++)
	{
		cin >> vertices >> edges;
		Graph g(vertices, edges);
		int u, v, w;
		for (int i = 0; i < edges; i++)
		{
			cin >> u >> v >> w;
			g.AddEdge(u, v, w);
		}
		if (g.IsCyclic() == true)
		{
			cout << "true ";
		}
		else
		{
			cout << "false ";
		}
	}

	return 0;
}