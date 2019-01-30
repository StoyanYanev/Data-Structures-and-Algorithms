#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<climits>

struct DisjointSets
{
	int *parent, *rank;
	int n;
	DisjointSets(int n)
	{
		this->n = n;
		parent = new int[n + 1];
		rank = new int[n + 1];
		for (int i = 0; i <= n; i++)
		{
			rank[i] = 0;
			parent[i] = i;
		}
	}
	int Find(int u)
	{
		if (u != parent[u])
		{
			parent[u] = Find(parent[u]);
		}
		return parent[u];
	}
	void Merge(int x, int y)
	{
		x = Find(x);
		y = Find(y);
		if (rank[x] > rank[y])
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
		}
		if (rank[x] == rank[y])
		{
			rank[y]++;
		}
	}
};

class Graph
{
public:
	Graph(int n)
	{
		vertices = n;
	};
	void Add(int u, int v, int w)
	{
		graph.push_back({ w,{ u,v } });
	}
	int MinimumSpanningTree()
	{
		int mstWeight = 0;
		std::sort(graph.begin(), graph.end());
		DisjointSets ds(vertices);
		std::vector<std::pair<int, std::pair<int, int>>>::iterator it;
		for (it = graph.begin(); it != graph.end(); it++)
		{
			int u = it->second.first;
			int v = it->second.second;

			int setU = ds.Find(u);
			int setV = ds.Find(v);

			if (setU != setV)
			{
				std::cout << u << " - " << v << std::endl;

				mstWeight += it->first;

				ds.Merge(setU, setV);
			}
		}
		return mstWeight;
	}
	~Graph() {};

private:
	int vertices;
	std::vector<std::pair<int, std::pair<int, int>>>graph;
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

	std::cout << "Edges of MST are" << std::endl;
	int mstWeight = g.MinimumSpanningTree();

	std::cout << std::endl;
	std::cout << "Weight of MST is " << mstWeight << std::endl;

	return 0;
}