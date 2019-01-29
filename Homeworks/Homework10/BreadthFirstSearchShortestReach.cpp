#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<list>
#include<queue>
using namespace std;

vector<string> split_string(string);

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s)
{
	vector<vector<int>>graph(n + 1, vector<int>(n + 1));
	vector<int>results;
	for (int i = 0; i < n + 1; i++)
	{
		results.push_back(-1);
	}
	int from;
	int to;
	for (int i = 0; i < edges.size(); i++)
	{
		from = edges[i][0];
		to = edges[i][1];
		graph[from][to] = 1;
		graph[to][from] = 1;
	}

	queue<int>q;
	q.push(s);
	results[s] = 0;
	while (q.empty() == false)
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph[v][i] == 1 && results[i] == -1)
			{
				q.push(i);
				results[i] = results[v] + 6;
			}
		}
	}
	if (results[0] == -1)
	{
		results.erase(results.begin() + 0);
	}
	for (int i = 0; i < results.size(); i++)
	{
		if (results[i] == 0)
		{
			results.erase(results.begin() + i);
		}
	}
	return results;
}

int main()
{
	//	ofstream fout(getenv("OUTPUT_PATH"));

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string nm_temp;
		getline(cin, nm_temp);

		vector<string> nm = split_string(nm_temp);

		int n = stoi(nm[0]);

		int m = stoi(nm[1]);

		vector<vector<int>> edges(m);
		for (int i = 0; i < m; i++) {
			edges[i].resize(2);

			for (int j = 0; j < 2; j++) {
				cin >> edges[i][j];
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		int s;
		cin >> s;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		vector<int> result = bfs(n, m, edges, s);

		for (int i = 0; i < result.size(); i++) {
			//fout << result[i];

			if (i != result.size() - 1) {
				//fout << " ";
			}
		}

		//fout << "\n";
	}

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}