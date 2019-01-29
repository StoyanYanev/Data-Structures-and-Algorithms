#include<iostream>
#include <vector>

void Quicksort(std::vector<int> &numbers, int start, int end);
int Partition(std::vector<int> &numbers, int start, int end);

int main()
{
	int n;
	int k;
	std::cin >> n >> k;
	std::vector<int> priceForToy;
	int price;
	for (int i = 0; i < n; i++)
	{
		std::cin >> price;
		priceForToy.push_back(price);
	}

	Quicksort(priceForToy, 0, n - 1);

	std::vector<int> numbersOfToys;
	int sum = 0;
	int diffrence = 0;
	for (int i = 0; i < priceForToy.size(); i++)
	{
		sum += priceForToy[i];
		numbersOfToys.push_back(priceForToy[i]);
		diffrence = k - sum;
		if (diffrence != 0)
		{
			if (diffrence < priceForToy[i])
			{
				sum -= priceForToy[i];
				numbersOfToys.pop_back();
			}
		}
	}

	std::cout << numbersOfToys.size() << std::endl;

	return 0;
}
void Quicksort(std::vector<int> &numbers, int start, int end)
{
	if (start < end)
	{
		int q = Partition(numbers, start, end);
		Quicksort(numbers, start, q - 1);
		Quicksort(numbers, q + 1, end);
	}
}

int Partition(std::vector<int> &numbers, int start, int end)
{
	int pivot = numbers[end];
	int i = start - 1;
	for (int j = start; j <= end - 1; j++)
	{
		if (numbers[j] <= pivot)
		{
			i++;
			std::swap(numbers[i], numbers[j]);
		}
	}
	std::swap(numbers[i + 1], numbers[end]);
	return (i + 1);
}