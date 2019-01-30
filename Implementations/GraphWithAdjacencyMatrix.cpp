#include<iostream>
#include<queue>

class Graph
{
public:
	Graph(int s)
	{
		size = s;
		matrix = new int*[size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new int[size];
		}
	};
	void Add(int from, int to)
	{
		//if the graph is directed
		matrix[from][to] = 1;

		//if the graph is undirected
		//matrix[to][from] = 1;
	}
	void BFS(int s)
	{
		bool* arr = new bool[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = false;
		}
		std::queue<int>q;
		q.push(s);
		arr[s] = true;
		int elem;
		while (q.empty() == false)
		{
			elem = q.front();
			std::cout << elem << " ";
			q.pop();
			for (int i = 0; i < size; i++)
			{
				if (matrix[elem][i] == 1 && arr[i] == false)
				{
					arr[i] = true;
					q.push(i);
				}
			}
		}
	}

	void DFS(int s)
	{
		bool* arr = new bool[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = false;
		}
		DFSUtil(s, arr);
	}
	~Graph()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	};

private:
	void DFSUtil(int s, bool visited[])
	{
		visited[s] = true;
		std::cout << s << " ";
		for (int i = 0; i < size; i++)
		{
			if (matrix[s][i] == 1 && visited[i] == false)
			{
				DFSUtil(i, visited);
			}
		}
	}

	int size;
	int** matrix;
};

int main()
{
	int n;
	//std::cin >> n;
	Graph g(4);
	g.Add(0, 1);
	g.Add(0, 2);
	g.Add(1, 2);
	g.Add(2, 0);
	g.Add(2, 3);
	g.Add(3, 3);

	g.DFS(2);
	std::cout << std::endl;
	g.BFS(2);

	return 0;
}