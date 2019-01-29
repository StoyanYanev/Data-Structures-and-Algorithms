#include <iostream>
#include<vector>
#include<climits>
#include<math.h>

class Graph
{
public:
	Graph(long long v, long long e)
	{
		E = e;
		V = v + 1;
		edges = new Edge[e];
		currentSize = 0;
	};
	void Add(long long u, long long v, long long w)
	{
		edges[currentSize].sorce = u;
		edges[currentSize].destination = v;
		if(w > 0)
        {
            w = w * (-1);
        }
		edges[currentSize].weight = w;
		currentSize++;
	}
	void FindTheLongestPath(long long startIndex, long long endIndex)
	{
		long long v = V;
		long long e = E;
		std::vector<long long> distance(v, LLONG_MAX);
		distance[startIndex] = 0;
		for (int i = 1; i <= V - 1; i++)
		{
			for (int j = 0; j < E; j++)
			{
				long long u = edges[j].sorce;
				long long v = edges[j].destination;
				long long w = edges[j].weight;
				if (distance[u] != LLONG_MAX && distance[u] + w < distance[v])
				{
					distance[v] = distance[u] + w;
				}
			}
		}
		if (distance[endIndex] != LLONG_MAX && distance[endIndex] != 0)
		{
			std::cout << distance[endIndex] * (-1) << std::endl;
		}
		else
		{
			std::cout << -1 << std::endl;
		}
	}
	~Graph()
	{
		delete[] edges;
	};

private:
	struct Edge
	{
		long long sorce;
		long long destination;
		long long weight;
	};
	long long V, E;
	Edge* edges;
	int currentSize;
};


int main()
{
	long long n;
	long long m;
	long long s;
	long long t;
	std::cin >> n >> m >> s >> t;
	long long v1;
	long long v2;
	long long w;
	Graph graph(n, m);
	for (int i = 0; i < m; i++)
	{
		std::cin >> v1 >> v2 >> w;
		graph.Add(v1, v2, w);
	}

	graph.FindTheLongestPath(s, t);

	return 0;
}