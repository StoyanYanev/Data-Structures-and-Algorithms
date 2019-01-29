#include <iostream>
#include <vector>
#include <algorithm>

struct Socks
{
	int shortSock;
	int longSock;
};

bool CheckIsValid(int n, int k);
bool CompareTwoSocks(Socks first, Socks second);

int main()
{
	//Implementation 1
	int n;
	int k;
	std::cin >> n >> k;
	if (CheckIsValid(n, k) == true)
	{
		int len;
		std::vector<int> lengthOfSocks;
		for (int i = 0; i < n; i++)
		{
			std::cin >> len;
			if (len >= 1)
			{
				lengthOfSocks.push_back(len);
			}
		}
		std::vector<Socks> allSocks;
		Socks s;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				s.shortSock = lengthOfSocks[i];
				s.longSock = lengthOfSocks[j];
				allSocks.push_back(s);
			}
		}
		std::sort(allSocks.begin(), allSocks.end(), CompareTwoSocks);
		std::cout << allSocks[k - 1].shortSock << " " << allSocks[k - 1].longSock << std::endl;
	}
	return 0;
}

bool CheckIsValid(int n, int k)
{
	if (n >= 3 && n <= 1000)
	{
		if (k >= 1 && k <= n * (n - 1) / 2)
		{
			return true;
		}
	}
	return false;
}

bool CompareTwoSocks(Socks first, Socks second)
{
	if ((first.longSock - first.shortSock) < (second.longSock - second.shortSock))
	{
		return true;
	}
	else if ((first.longSock - first.shortSock) == (second.longSock - second.shortSock))
	{
		if (first.shortSock < second.shortSock)
		{
			return true;
		}
	}
	return false;
}