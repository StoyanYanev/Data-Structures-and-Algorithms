#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<stack>

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
	void BFS(int start)
	{
		vector<bool>visited(v, false);
		queue<int> q;

		visited[start] = true;
		q.push(start);

		int elem;
		long long allSum = 0;
		vector<int> distance(v, 0); // save min distance from start(vertex) to the other vertices
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
	int k;
	cin >> k;

	Graph g(k);
	int v1;
	int v2;
	int w;
	for (int i = 0; i < k; i++)
	{
		cin >> v1 >> v2 >> w;
		g.Add(v1, v2, w);
	}

	return 0;
}