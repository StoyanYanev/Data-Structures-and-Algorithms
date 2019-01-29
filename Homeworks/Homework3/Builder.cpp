#include<iostream>
#include<vector>
#include <algorithm>

struct Buildings
{
	int height;
	int price;
};

void InputHeight(std::vector<Buildings> &buildings, int n);
void InputPrice(std::vector<Buildings> &buildings, int n);
long long FindBestSum(std::vector<Buildings> &buildings);

int main()
{
	int n;
	std::cin >> n;
	std::vector<Buildings> buildings;

	InputHeight(buildings, n);
	InputPrice(buildings, n);

	long long sum = FindBestSum(buildings);
	std::cout << sum << std::endl;

	return 0;
}

void InputHeight(std::vector<Buildings>& buildings, int n)
{
	Buildings build;
	for (int i = 0; i < n; i++)
	{
		std::cin >> build.height;
		buildings.push_back(build);
	}
}

void InputPrice(std::vector<Buildings>& buildings, int n)
{
	int p;
	for (int i = 0; i < n; i++)
	{
		std::cin >> p;
		buildings[i].price = p;
	}
}

long long FindBestSum(std::vector<Buildings>& buildings)
{
	long long sum = 0;
	long long result;
	std::vector<long long> s;
	for (int i = 0; i < buildings.size(); i++)
	{
		for (int j = 0; j < buildings.size(); j++)
		{
			if (i != j)
			{
				if ((buildings[j].height - buildings[i].height) > 0)
				{
					sum += (buildings[j].height - buildings[i].height) * buildings[j].price;
				}
				else
				{
					sum += (buildings[j].height - buildings[i].height) * buildings[j].price*(-1);
				}
			}
		}
		s.push_back(sum);
		sum = 0;
	}
	std::sort(s.begin(), s.end());
	result = s[0];

	return result;
}