#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;

class Graph
{
public:
	Graph(int n)
	{
		v = n + 1;
		graph = new vector<pair<int, int>>[v];
	}
	void Add(int u, int v, int w)
	{
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	void FindShortestPath(int start)
	{
		// use BFS
		vector<bool>visited(v, false);
		queue<int> q;

		visited[start] = true;
		q.push(start);

		int elem;
		long long allSum = 0;
		vector<int> distance(v, 0);
		while (q.empty() == false)
		{
			elem = q.front();
			q.pop();
			for (auto &c : graph[elem])
			{
				if (visited[c.first] == false)
				{
					visited[c.first] = true;
					q.push(c.first);
					distance[c.first] = distance[elem] + 1;
				}
			}
		}
		for (int i = 0; i < distance.size(); i++)
		{
			allSum += distance[i];
		}
		cout << allSum << endl;
	}
	~Graph()
	{
		delete[] graph;
	}
private:
	int v;
	vector<pair<int, int>>*graph;
};

int main()
{
	ios_base::sync_with_stdio(false);
	int k;
	cin >> k;

	Graph g(k);
	int x;
	int y;
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		g.Add(x, y, 1); // 1 is the path between orderes and deliveries
	}
	g.FindShortestPath(0);

	return 0;
}