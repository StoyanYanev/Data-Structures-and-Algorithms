#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
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
	void FindTheShortestPaht(int start)
	{
		std::set<std::pair<int, int>>s;
		std::vector<int>distance(v, INT_MAX);

		s.insert(std::make_pair(0, start));
		distance[start] = 0;

		int u;
		while (s.empty() == false)
		{
			std::pair<int, int>temp = *(s.begin());
			s.erase(s.begin());
			u = temp.second;
			for (auto &c : graph[u])
			{
				int v = c.first;
				int w = c.second;
				if (distance[u] + w < distance[v])
				{
					if (distance[v] != INT_MAX)
					{
						s.erase(s.find(std::make_pair(distance[v], v)));
					}
					distance[v] = distance[u] + w;
					s.insert(std::make_pair(distance[v], v));
				}
			}
		}

		for (int i = 0; i < distance.size(); i++)
		{
			if (distance[i]!=INT_MAX)
			{
				std::cout << i << " " << distance[i] << std::endl;
			}
		}
	}
	~Graph()
	{
		delete[] graph;
	};

private:
	int v;
	std::vector<std::pair<int, int>>* graph;
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
	//int elem;
	//std::cout << "Enter the start vertex: ";
	//std::cin >> elem;
	g.FindTheShortestPaht(0);

	return 0;
}