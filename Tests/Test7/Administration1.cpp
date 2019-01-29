#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	/**************************************FAST SOLUTION**************************************/
	ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;
	vector<long long> countNumbers(n + 1);
	list<long long> numbers;

	long long currentNumber;
	for (int i = 0; i < n; i++)
	{
		cin >> currentNumber;
		countNumbers[currentNumber] += 1; //count how many times every number repeats
		numbers.push_back(currentNumber);
	}

	list<long long>::iterator it;
	vector<long long> repeatedNumbers;
	for (it = numbers.begin(); it != numbers.end(); ++it)
	{
		if (countNumbers[*it] != 0)
		{
			if (countNumbers[*it] == 1) // if the number occurs 1 time than print it and mark it as not occured
			{
				cout << *it << " ";
				countNumbers[*it] = 0;
			}
			else
			{
				// if the number repeats more than 1 time than save it in the other vector
				repeatedNumbers.push_back(*it); 
				countNumbers[*it] = 0; // and mark it as not occured
			}
		}
	}

	for (int i = 0; i < repeatedNumbers.size(); i++)
	{
		cout << repeatedNumbers[i] << " ";
	}

	return 0;
}