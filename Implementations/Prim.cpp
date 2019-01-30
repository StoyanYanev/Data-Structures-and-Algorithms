#include<iostream>
#include<set>
#include<vector>
#include<functional>
#include<queue>
#include<climits>

class Graph
{
public:
	Graph(int n)
	{
		v = n + 1;
		graph = new std::vector<std::pair<int, int>>[v];
	};
	void Add(int u, int v, int w)
	{
		graph[u].push_back(std::make_pair(v, w));
		graph[v].push_back(std::make_pair(u, w));
	}
	void MinimumSpanningTree()
	{
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>s;

		std::vector<int>distance(v, INT_MAX);
		std::vector<int>parent(v, -1);
		std::vector<bool>visited(v, false);

		int src = 0;

		s.push(std::make_pair(0, src));
		distance[src] = 0;
		int u;

		while (s.empty() == false)
		{
			u = s.top().second;
			s.pop();
			visited[u] = true;
			for (auto &c : graph[u])
			{
				int v = c.first;
				int w = c.second;
				if (visited[v] == false && w < distance[v])
				{
					distance[v] = w;
					s.push(std::make_pair(distance[v], v));
					parent[v] = u;
				}
			}
		}
		// Print edges of Minimum Spanning Tree  
		for (int i = 1; i < v - 1; ++i)
		{
			std::cout << parent[i] << "-" << i << std::endl;
		}
	}
	~Graph()
	{
		delete[] graph;
	};

private:
	int v;
	std::vector<std::pair<int, int>>*graph;
};

int main()
{
	int vertices = 9;
	//std::cin >> vertices;

	Graph g(vertices);
	g.Add(0, 1, 4);
	g.Add(0, 7, 8);
	g.Add(1, 2, 8);
	g.Add(1, 7, 11);
	g.Add(2, 3, 7);
	g.Add(2, 8, 2);
	g.Add(2, 5, 4);
	g.Add(3, 4, 9);
	g.Add(3, 5, 14);
	g.Add(4, 5, 10);
	g.Add(5, 6, 2);
	g.Add(6, 7, 1);
	g.Add(6, 8, 6);
	g.Add(7, 8, 7);

	/*int v1;
	int v2;
	int w;
	for (int i = 0; i < vertices; i++)
	{
	std::cin >> v1 >> v2 >> w;
	g.Add(v1, v2, w);
	}*/

	g.MinimumSpanningTree();

	return 0;
}