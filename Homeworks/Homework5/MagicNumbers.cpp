#include <iostream>
#include <vector>

using namespace std;

const int BIGGERST_ONE_DIGIT_MAGIC_NUMBER = 9;

void MagicNumbers(vector<long long>& numbers, long long n)
{
	long long firstMagicNumber;
	long long secondMagicNumber;

	for (long long i = 0; i < numbers.size(); i++)
	{
		firstMagicNumber = (numbers[i] * 10) + (numbers[i] % 10 - 2);
		secondMagicNumber = (numbers[i] * 10) + (numbers[i] % 10 + 2);

		if (firstMagicNumber > n && secondMagicNumber > n)
		{
			break;
		}
		if (firstMagicNumber <= n && (numbers[i] % 10) != 1 && (numbers[i] % 10) != 0)
		{
			numbers.push_back(firstMagicNumber);
		}
		if (secondMagicNumber <= n && (numbers[i] % 10) != 8 && (numbers[i] % 10) != 9)
		{
			numbers.push_back(secondMagicNumber);
		}
	}
}

void MagicNumbersWithOneDigits(vector<long long>& num, long long n)
{
	for (int i = 1; i <= n; i++)
	{
		num.push_back(i);
	}
}

void Print(std::vector<long long> num)
{
	for (int i = 0; i < num.size(); i++)
	{
		std::cout << num[i] << " ";
	}
}

int main()
{
	long long n;
	std::cin >> n;

	vector<long long> numbers;

	if (n <= 9)
	{
		MagicNumbersWithOneDigits(numbers, n);
		Print(numbers);
	}
	else
	{
		MagicNumbersWithOneDigits(numbers, BIGGERST_ONE_DIGIT_MAGIC_NUMBER);
		MagicNumbers(numbers, n);
		Print(numbers);
	}

	return 0;
};