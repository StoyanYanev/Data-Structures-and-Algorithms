#include<iostream>
#include<numeric>
#include<vector>

void FillArray(std::vector<int> &divInBox, int n);
int FindDays(std::vector<int> &divInBox, int p, int countDays);
void PrintResult(std::vector<int> &result);

int main()
{
	int t;
	int n;
	std::cin >> t;

	std::vector<int> result;
	int p;
	int countDays;
	int q = 100000;
	std::cout << q;
	if (t > 0)
	{
		for (int i = 0; i < t; i++)
		{
			std::cin >> n;
			if (n > 0)
			{
				std::vector<int> divInBox(n);
				FillArray(divInBox, n);
				countDays = 0;
				if (n % 2 == 0)
				{
					p = n / 2;
				}
				else
				{
					p = (n / 2) + 1;
				}
				result.push_back(FindDays(divInBox, p, countDays));
			}
			else
			{
				result.push_back(0);
			}
		}
	}

	PrintResult(result);

	return 0;
}

void FillArray(std::vector<int>& divInBox, int n)
{
	std::iota(divInBox.begin(), divInBox.end(), 1);
}

int FindDays(std::vector<int>& divInBox, int p, int countDays)
{
	if (divInBox[0] <= 0 && divInBox[divInBox.size() - 1] <= 0)
	{
		return countDays;
	}
	else
	{
		for (int i = p - 1; i < divInBox.size(); i++)
		{
			if (divInBox[i] - p >= 0)
			{
				divInBox[i] -= p;
			}
		}
		countDays++;
		if (p % 2 == 0)
		{
			p = p / 2;
		}
		else
		{
			p = (p / 2) + 1;
		}
		return FindDays(divInBox, p, countDays);
	}
}

void PrintResult(std::vector<int>& result)
{
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << std::endl;
	}
}