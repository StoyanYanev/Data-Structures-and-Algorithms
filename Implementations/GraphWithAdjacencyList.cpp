#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

class Graph
{
public:
	Graph(int vertices, int edges)
	{
		v = vertices + 1;
		e = edges;
		graph = new list<std::pair<long long, long long>>[v];
	};
	void AddEdge(long long u, long long v, long long w)
	{
		graph[u].push_back(make_pair(v, w));
	}

	void DFS(int start)
	{
		stack<pair<int, int>> s;
		vector<bool> visited(v, false);

		s.push(make_pair(0, start));

		int elem;

		while (s.empty() == false)
		{
			elem = s.top().first;
			cout << elem << " ";
			s.pop();
			if (visited[elem] == false)
			{
				visited[elem] = true;
			}
			for (auto i = graph[elem].begin(); i != graph[elem].end(); ++i)
			{
				if (visited[i->first] == false)
				{
					s.push(*i);
				}
			}
		}
	}
	~Graph()
	{
		delete[] graph;
	};

private:
	int v;
	int e;
	list<pair<long long, long long>> *graph;
};

int main()
{
	int vertices;
	int edges;
	cin >> edges >> vertices;
	Graph g(vertices, edges);
	long long u, v, w;
	for (int i = 0; i < edges; i++)
	{
		cin >> u >> v >> w;
		g.AddEdge(u, v, w);
	}

	int elem;
	cout << "Enter start vertex: ";
	cin >> elem;
	g.DFS(elem);

	return 0;
}