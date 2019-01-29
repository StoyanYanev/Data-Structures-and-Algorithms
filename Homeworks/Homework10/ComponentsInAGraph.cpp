#include<iostream>
#include<vector>
#include<list>
using namespace std;

/*
* Complete the componentsInGraph function below.
*/
vector<int> componentsInGraph(vector<vector<int>> gb)
{
	vector<list<int>*>graph(2 * gb.size() + 1);
	int from;
	int to;
	for (int i = 0; i < gb.size(); i++)
	{
		from = gb[i][0];
		to = gb[i][1];
		if (graph[from] == NULL && graph[to] == NULL)
		{
			graph[from] = new list<int>;
			graph[to] = graph[from];
			graph[from]->push_back(from);
			graph[from]->push_back(to);
		}
		else if (graph[from] == NULL)
		{
			graph[from] = graph[to];
			graph[from]->push_back(from);
		}
		else if (graph[to] == NULL)
		{
			graph[to] = graph[from];
			graph[to]->push_back(to);
		}
		else if (graph[from] != graph[to])
		{
			if (graph[from]->size() < graph[to]->size())
			{
				list<int>* temp = graph[from];
				for (int i : *temp)
				{
					graph[i] = graph[to];
				}
				graph[to]->splice(graph[to]->end(), *temp);
				delete temp;
			}
			else
			{
				list<int>* temp = graph[to];
				for (int i : *temp)
				{
					graph[i] = graph[from];
				}
				graph[from]->splice(graph[from]->end(), *temp);
				delete temp;
			}
		}
	}
	vector<int> minAndMax;
	int min = gb.size() * 2;
	int max = 0;
	for (auto i : graph)
	{
		if (i != NULL)
		{
			if (i->size() < min)
			{
				min = i->size();
			}
			 if (i->size() > max)
			{
				max = i->size();
			}
		}
	}
	minAndMax.push_back(min);
	minAndMax.push_back(max);
	return minAndMax;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<vector<int>> gb(n);
	for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
		gb[gb_row_itr].resize(2);

		for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
			cin >> gb[gb_row_itr][gb_column_itr];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	vector<int> result = componentsInGraph(gb);

	for (int SPACE_itr = 0; SPACE_itr < result.size(); SPACE_itr++) {
		fout << result[SPACE_itr];

		if (SPACE_itr != result.size() - 1) {
			fout << " ";
		}
	}

	fout << "\n";

	fout.close();

	return 0;
}
