#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BinarySearch(vector<int> &numbers, int start, int end, int x)
{
	if (start <= end)
	{
		int middle = start + (end - start) / 2;

		if (numbers[middle] == x)
		{
			return middle;
		}
		else if (numbers[middle] > x)
		{
			return BinarySearch(numbers, start, middle - 1, x);
		}
		else
		{
			return BinarySearch(numbers, middle + 1, end, x);

		}
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;

	vector<int> numbers;
	int currentNumber;

	for (int i = 0; i < n; i++)
	{
		cin >> currentNumber;
		numbers.push_back(currentNumber);
	}

	std::sort(numbers.begin(), numbers.end());

	int x;
	std::cout << "Enter the element which you want to find: ";
	cin >> x;

	int index = BinarySearch(numbers, 0, numbers.size() - 1, x);
	if (index >= 0)
	{
		std::cout << "Element is present at index: " << index << std::endl;
	}
	else
	{
		std::cout << "Element is not present in array" << std::endl;
	}

	return 0;
}