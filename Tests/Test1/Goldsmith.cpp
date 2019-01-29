#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int>numbers;
	int currentNumber;
	for (int i = 0; i < n; i++)
	{
		std::cin >> currentNumber;
		numbers.push_back(currentNumber);
	}

	bool isExist = false;
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = 0; j < numbers.size(); j++)
		{
			for (int k = 0; k < numbers.size(); k++)
			{
				if ((numbers[i] + numbers[j] == numbers[k]) && i != j && j != k && k != i)
				{
					isExist = true;
				}
			}
		}
	}

	if (isExist == true)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}

	return 0;
}