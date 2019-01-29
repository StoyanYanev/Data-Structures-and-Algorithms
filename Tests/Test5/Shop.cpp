#include <iostream>
#include <cstdio>
#include<map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	map<int, int>orders;
	map<int, int>::iterator it;
	int id;
	for (int i = 0; i < n; i++)
	{
		cin >> id;
		it = orders.find(id);
		if (it != orders.end())
		{
			it->second = it->second + 1;
		}
		else
		{
			orders.insert({ id,1 });
		}
	}

	int undeliveredProducts = 0;
	int peopleWithUndeliveredProducts = 0;
	for (it = orders.begin(); it != orders.end(); ++it)
	{
		if (it->second >= 10)
		{
			while (it->second >= 10)
			{
				it->second = it->second - 10;
			}
			if (it->second > 0)
			{
				undeliveredProducts += it->second;
				peopleWithUndeliveredProducts++;
			}
		}
		else
		{
			undeliveredProducts += it->second;
			peopleWithUndeliveredProducts++;
		}
	}
	cout << peopleWithUndeliveredProducts << " " << undeliveredProducts << endl;

	return 0;
}