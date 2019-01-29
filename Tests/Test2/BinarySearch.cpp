#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BinarySearch(vector<int> &numbers, int start, int end, int x, int &count);

int main()
{
	int n;
	cin >> n;

	vector<int> numbers;
	int count = 0;
	int currentNumber;

	for (int i = 0; i < n; i++)
	{
		cin >> currentNumber;
		numbers.push_back(currentNumber);
	}

	int q;
	cin >> q;
	int x;
	int currentInd;
	vector<int> indexes;
	vector<int> numberOfChecks;
	
	while (q > 0)
	{
		cin >> x;
		currentInd = BinarySearch(numbers, 0, numbers.size() - 1, x, count);
		indexes.push_back(currentInd);
		numberOfChecks.push_back(count);
		count = 0;
		q--;
	}

	for (int i = 0; i < indexes.size(); i++)
	{
		cout << indexes[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < numberOfChecks.size(); i++)
	{
		cout << numberOfChecks[i] << " ";
	}
	cout << endl;

	return 0;
}
int BinarySearch(vector<int> &numbers, int start, int end, int x, int &count)
{
	if (start <= end)
	{
		int middle = start + (end - start) / 2;
		count++;
		if (numbers[middle] == x) 
		{ 
			return middle; 
		}
		else if (numbers[middle] > x)
		{
			return BinarySearch(numbers, start, middle - 1, x, count);
		}
		else
		{
			return BinarySearch(numbers, middle + 1, end, x, count);

		}
	}
	return -1;
}