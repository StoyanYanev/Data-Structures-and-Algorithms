#include <iostream>
#include<vector>
#include<set>
#include<list>
#include <algorithm>
#include<climits>

class Graph
{
public:
	Graph(int vertex)
	{
		m_v = vertex + 1;
		m_graph = new std::list<std::pair<long long, long long>>[m_v];
	}
	void AddEdge(long long u, long long v, long long w)
	{
		m_graph[u].push_back(std::make_pair(v, w));
		m_graph[v].push_back(std::make_pair(u, w));
	}
	void FindTheShortestPath(int sorce)
	{
		std::set<std::pair<long long, long long>> storeVerteces;
		std::vector<long long> distance(m_v, LLONG_MAX);

		storeVerteces.insert(std::make_pair(0, sorce));
		distance[sorce] = 0;

		while (storeVerteces.empty() == false)
		{
			std::pair<long long, long long> temp = *(storeVerteces.begin());
			storeVerteces.erase(storeVerteces.begin());

			long long u = temp.second;
			std::list<std::pair<long long, long long>>::iterator it;
			for (it = m_graph[u].begin(); it != m_graph[u].end(); ++it)
			{
				long long v = (*it).first;
				long long w = (*it).second;
				if (distance[v] > distance[u] + w)
				{
					if (distance[v] != LLONG_MAX)
					{
						storeVerteces.erase(storeVerteces.find(std::make_pair(distance[v], v)));
					}
					distance[v] = distance[u] + w;
					storeVerteces.insert(std::make_pair(distance[v], v));
				}
			}
		}
		PrintDistance(distance);
	}

	~Graph()
	{
		delete[] m_graph;
	};

private:
	void PrintDistance(std::vector<long long> &distance)
	{
		for (int i = 1; i < m_v; i++)
		{
			if (distance[i] != 0 && distance[i] != LLONG_MAX)
			{
				std::cout << distance[i] << " ";
			}
			else
			{
				if (distance[i] == LLONG_MAX)
				{
					std::cout << -1 << " ";
				}
			}
		}
	}
	int m_v;
	std::list<std::pair<long long, long long>> *m_graph;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	int n, m;
	long long u, v, w;
	int s;

	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n >> m;
		Graph graph(n);
		for (int i = 0; i < m; i++)
		{
			std::cin >> u >> v >> w;
			graph.AddEdge(u, v, w);
		}
		std::cin >> s;
		graph.FindTheShortestPath(s);
		std::cout << std::endl;
	}

	return 0;
}