#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

void InputElements(std::vector<long long> &numbers, int n);
int FindFirstRepeatedElem(std::vector<long long> &numbers, int left, int right, long long sNumber);
int FindSecondRepeatedElem(std::vector<long long> &numbers, int left, int right, long long sNumber);
void PrintResult(std::vector<int> &result);

int main()
{
	int n;
	int q;
	std::vector<long long> numbers;
	std::vector<int> result;
	long long p;

	std::cin >> n;
	InputElements(numbers, n);
	std::sort(numbers.begin(), numbers.end());
	std::cin >> q;

	for (int i = 0; i < q; i++)
	{
		std::cin >> p;
		if (numbers[1] == p && numbers[numbers.size() - 1] == p)
		{
			result.push_back(1);
			result.push_back(numbers.size() - 1);
		}
		else
		{
			result.push_back(FindFirstRepeatedElem(numbers, 0, n, p));
			result.push_back(FindSecondRepeatedElem(numbers, 0, n, p));
		}
	}

	PrintResult(result);

	return 0;
}

void InputElements(std::vector<long long>& numbers, int n)
{
	long long currentElement;
	numbers.push_back(LLONG_MIN);
	for (int i = 0; i < n; i++)
	{
		std::cin >> currentElement;
		numbers.push_back(currentElement);
	}
}

int FindFirstRepeatedElem(std::vector<long long> &numbers, int left, int right, long long sNumber)
{
	if (right >= left)
	{
		int middle = left + (right - left) / 2;
		if ((middle == 0 || sNumber > numbers[middle - 1]) && numbers[middle] == sNumber)
		{
			return middle;
		}
		else if (sNumber > numbers[middle])
		{
			return FindFirstRepeatedElem(numbers, middle + 1, right, sNumber);
		}
		else
		{
			return FindFirstRepeatedElem(numbers, left, middle - 1, sNumber);
		}
	}
	return -1;
}

int FindSecondRepeatedElem(std::vector<long long>& numbers, int left, int right, long long sNumber)
{
	if (right >= left)
	{
		int middle = left + (right - left) / 2;
		if (((middle == (numbers.size() - 1)) || sNumber < numbers[middle + 1]) && (numbers[middle] == sNumber))
		{
			return middle;
		}
		else if (numbers[middle] > sNumber)
		{
			return FindSecondRepeatedElem(numbers, left, middle - 1, sNumber);
		}
		else
		{
			return FindSecondRepeatedElem(numbers, middle + 1, right, sNumber);
		}
	}
	return -1;
}

void PrintResult(std::vector<int>& result)
{
	for (int i = 0; i < result.size(); i += 2)
	{
		std::cout << result[i] << " " << result[i + 1] << std::endl;;
	}
}