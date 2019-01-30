#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_ELEMENTS = 1000000;

void CountingSort(vector<int>&nums, vector<int>& sortedNums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		sortedNums[nums[i]]++;
	}
}

void PrintSortedArray(vector<int>& sortedNums)
{
	for (int i = 0; i < sortedNums.size(); i++)
	{
		if (sortedNums[i] > 0)
		{
			cout << i << " ";
		}
	}
}

int main()
{
	int n;
	cin >> n;

	/*Ànother way*/
	//vector<int>numbers;
	vector<int>sortedNums(MAX_ELEMENTS);
	int currNum;
	for (int i = 0; i < n; i++)
	{
		cin >> currNum;
		sortedNums[currNum]++;
		//numbers.push_back(currNum);
	}

	//CountingSort(numbers, sortedNums);
	PrintSortedArray(sortedNums);

	return 0;
}