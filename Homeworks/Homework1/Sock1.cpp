#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

const int ROW = 2;

bool SortRow(const vector<int> &first, const vector<int> &second);

int main()
{
	//Implementation 2
	int n;
	int k;
	cin >> n >> k;
	vector<int> lengthOfSocks;
	int index = 0;
	int lenOfSocks;
	while (index < n)
	{
		cin >> lenOfSocks;
		lengthOfSocks.push_back(lenOfSocks);
		index++;
	}
	int combinations = (n * (n - 1)) / 2;
	vector<int> allCombinationOfSocks;
	for (int i = 0; i < lengthOfSocks.size(); i++)
	{
		for (int j = i + 1; j < lengthOfSocks.size(); j++)
		{
			allCombinationOfSocks.push_back(lengthOfSocks[i]);
			allCombinationOfSocks.push_back(lengthOfSocks[j]);
		}
	}
	vector<vector<int>> allSocks(combinations, vector<int>(ROW));
	int ind = 0;
	int p, f;
	for (int i = 0; i < combinations; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			allSocks[i][j] = allCombinationOfSocks[ind];
			ind++;
		}
	}
	sort(allSocks.begin(), allSocks.end(), SortRow);

	cout << allSocks[k - 1][ROW - 2] << " " << allSocks[k - 1][ROW - 1] << endl;

	return 0;
}

bool SortRow(const vector<int>& first, const vector<int>& second)
{
	if (first[1] - first[0] == second[1] - second[0])
		return first[0] < second[0];

	return first[1] - first[0] < second[1] - second[0];
}