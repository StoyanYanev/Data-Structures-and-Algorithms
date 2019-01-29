#include<iostream>
#include<set>

int main()
{
	int m;
	int n;
	std::cin >> m;
	std::cin >> n;

	std::set<int>players;
	players.insert(m);

	int firstPlayer;
	int secondPlayer;

	while (n > 0)
	{
		std::cin >> firstPlayer >> secondPlayer;
		if (players.find(firstPlayer) != players.end())
		{
			players.insert(secondPlayer);
		}
		n--;
	}
	std::cout << players.size() << std::endl;

	return 0;
}