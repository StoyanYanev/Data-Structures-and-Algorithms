#include<iostream>
#include<vector>
#include <algorithm>

bool IsValid(int n, int k);
int FindMinSum(std::vector<int> arr, int n, int k);

int main()
{
	int n;
	int k;
	std::cin >> n >> k;
	if (IsValid(n, k) == true)
	{
		std::vector<int> items;
		int price;
		for (int i = 0; i < n; i++)
		{
			std::cin >> price;
			if (price >= 1 && price <= 10000)
			{
				items.push_back(price);
			}
		}
		std::sort(std::begin(items), std::end(items));
		std::cout << FindMinSum(items, n, k) << std::endl;
	}
	return 0;
}

bool IsValid(int n, int k)
{
	if ((n >= 1 && n <= 100000) && (k >= 2 && k <= 100))
	{
		return true;
	}
	return false;
}

int FindMinSum(std::vector<int> arr, int n, int k)
{
	int restFromSum = 0;
	int elementsNotInGroups = n % k;
	for (int i = 0; i < arr.size(); i++)
	{
		if (i != elementsNotInGroups)
		{
			restFromSum += arr[i];
		}
		else
		{
			elementsNotInGroups = elementsNotInGroups + k;
		}
	}
	return restFromSum;
}