#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include <climits>

using namespace std;

class Graph
{
public:
	Graph(long long n)
	{
		v = n + 1;
		graph = new vector<pair<long long, long long>>[v];
	}
	void Add(long long u, long v, long w)
	{
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	void FindShortestPath(long long start)
	{
		set<pair<long long, long long>>s;
		vector<long long>distance(v, LLONG_MAX);
		s.insert(make_pair(0, start));
		distance[start] = 0;
		long long u;
		while (s.empty() == false)
		{
			pair<long long, long long>temp = *(s.begin());
			s.erase(s.begin());
			u = temp.second;
			for (auto &c : graph[u])
			{
				long long v = c.first;
				long long w = c.second;
				if (distance[u] + w < distance[v])
				{
					if (distance[v] != LLONG_MAX)
					{
						s.erase(s.find(make_pair(distance[v], v)));
					}
					distance[v] = distance[u] + w;
					s.insert(make_pair(distance[v], v));
				}
			}
		}
		for (int i = 1; i < distance.size(); i++)
		{
			if (i != start && distance[i] != LLONG_MAX)
			{
				cout << distance[i] << " ";
			}
			else if (distance[i] == LLONG_MAX)
			{
				cout << -1 << " ";
			}
		}
	}
private:
	long long v;
	vector<pair<long long, long long>>*graph;
};

int main() {
	ios_base::sync_with_stdio(false);
	long long n, m;
	cin >> n >> m;
	long long u, v, w;
	Graph g(n);
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		g.Add(u, v, w);
	}
	long long s;
	cin >> s;
	g.FindShortestPath(s);

	return 0;
}