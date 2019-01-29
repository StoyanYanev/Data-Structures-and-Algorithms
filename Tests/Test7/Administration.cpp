#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	/**************************************SLOW SOLUTION**************************************/
	ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;
	vector<long long> countNumbers(n + 1);
	list<long long> numbers;
	list<long long> uniqueNumbers;

	long long currentNumber;
	for (int i = 0; i < n; i++)
	{
		cin >> currentNumber;
		countNumbers[currentNumber] += 1; // count how many times every number repeats
		numbers.push_back(currentNumber);
		uniqueNumbers.push_back(currentNumber);
	}

	for (int i = 0; i < countNumbers.size(); i++)
	{
		if (countNumbers[i] > 1)
		{
			uniqueNumbers.remove(i); // remove all repeated numbers and store all unique numbers (unique numbers means that the number is repeated 1 time in the list)
		}
		else
		{
			numbers.remove(i); // remove all unique numbers and store all repeated numbers
		}
	}

	list<long long>::iterator it;
	list<long long> l;
	for (it = numbers.begin(); it != numbers.end(); ++it)
	{
		if (find(l.begin(), l.end(), *it) == l.end()) // remove all repeated numbers in list-numbers
													 //ex: 6 2 6 3 2 3 => 6 2 3
		{
			l.push_back(*it);
		}
	}

	for (it = uniqueNumbers.begin(); it != uniqueNumbers.end(); ++it)
	{
		cout << *it << " ";
	}

	for (it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";
	}

	return 0;
}