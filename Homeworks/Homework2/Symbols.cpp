#include<iostream>
#include <string>
#include <vector>

void Quicksort(std::string symbols, int start, int end);
int Partition(std::string symbols, int start, int end);

int main()
{
	std::string symbols;
	std::getline(std::cin, symbols);
	int len = symbols.length();

	Quicksort(symbols, 0, len - 1);

	int maxCount = 0;
	int counter = 1;
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j <= len - 1; j++)
		{
			if (symbols[i] != symbols[j])
			{
				break;
			}
			counter++;
		}
		if (counter > maxCount)
		{
			maxCount = counter;
		}
		counter = 1;
	}
	if (maxCount - 1 > len - maxCount)
	{
		std::cout << "No" << std::endl;
	}
	else
	{
		std::cout << "Yes" << std::endl;
	}

	return 0;
}

void Quicksort(std::string symbols, int start, int end)
{
	if (start < end)
	{
		int q = Partition(symbols, start, end);
		Quicksort(symbols, start, q - 1);
		Quicksort(symbols, q + 1, end);
	}
}

int Partition(std::string symbols, int start, int end)
{
	int pivot = symbols[end];
	int i = start - 1;
	for (int j = start; j <= end - 1; j++)
	{
		if (symbols[j] <= pivot)
		{
			i++;
			std::swap(symbols[i], symbols[j]);
		}
	}
	std::swap(symbols[i + 1], symbols[end]);
	return (i + 1);
}