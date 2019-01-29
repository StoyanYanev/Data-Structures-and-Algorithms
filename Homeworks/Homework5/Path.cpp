#include<iostream>
#include<vector>
#include<string>

void SeenGreenStone(long long index, std::vector<long long> &numbers);
void SeenBlueStone(long long index, std::vector<long long> &numbers);

int main()
{
	long long n;
	std::cin >> n;

	long long num;
	std::string colorOfStones;
	std::vector<long long> numbers;
	
	while (n > 0)
	{
		std::cin >> colorOfStones;
		std::cin >> num;
		numbers.push_back(num);

		if (colorOfStones == "green")
		{
			SeenGreenStone(numbers.back(), numbers);
		}
		else if (colorOfStones == "blue")
		{
			SeenBlueStone(numbers.back(), numbers);
		}

		n--;
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

void SeenGreenStone(long long index, std::vector<long long> &numbers)
{
	numbers.pop_back();
	long long sum = 0;
	for (long long i = index; i > 0; i--)
	{
		sum += numbers.back();
		numbers.pop_back();
	}
	numbers.push_back(sum);
}

void SeenBlueStone(long long index, std::vector<long long> &numbers)
{
	numbers.pop_back();
	long long max = numbers.back();
	for (long long i = index; i > 0; i--)
	{
		if (max < numbers.back())
		{
			max = numbers.back();
		}
		numbers.pop_back();
	}
	numbers.push_back(max);
}