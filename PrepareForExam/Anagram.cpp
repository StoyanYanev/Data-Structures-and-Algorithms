#include<iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<climits>

using namespace std;

bool IsAnagram(string firstWord, string secondWord)
{
	if (firstWord.compare(secondWord) == 0)
	{
		return true;
	}
	return false;
}

void RemoveEqualSymbols(string &firstWord, string &secondWord)
{
	int indexOfSymbol = 0;
	for (int i = 0; i < firstWord.length(); i++)
	{
		indexOfSymbol = secondWord.find(firstWord[i], indexOfSymbol);
		if (indexOfSymbol >= 0)
		{
			firstWord[i] = ' ';
			secondWord[indexOfSymbol] = ' ';
		}
		indexOfSymbol = 0;
	}
	firstWord.erase(remove(firstWord.begin(), firstWord.end(), ' '), firstWord.end());
	secondWord.erase(remove(secondWord.begin(), secondWord.end(), ' '), secondWord.end());
}

long long FindMinSum(string firstWord, string secondWord)
{
	long long minSum = 0;
	long long currentSum = 0;
	long long minDistanceBetweenSymbols = LLONG_MAX;
	int indexOfMinDistance = 0;

	for (int i = 0; i < firstWord.length(); i++)
	{
		for (int j = 0; j < secondWord.length(); j++)
		{
			currentSum = (int)(secondWord[j] - firstWord[i]);
			if (currentSum < 0)
			{
				currentSum = (26 - abs(currentSum)); // 26 number of alphabet
			}
			if (currentSum < minDistanceBetweenSymbols)
			{
				minDistanceBetweenSymbols = currentSum;
				indexOfMinDistance = j;
			}
		}
		if (minSum != LLONG_MAX)
		{
			minSum += minDistanceBetweenSymbols;
			minDistanceBetweenSymbols = LLONG_MAX;
			secondWord.erase(secondWord.begin() + indexOfMinDistance);
		}
	}
	return minSum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	long long minSum = 0;

	for (int i = 0; i < t; i++)
	{
		string firstWord;
		string secondWord;

		cin >> firstWord;
		cin >> secondWord;

		//sort string to compare it
		sort(firstWord.begin(), firstWord.end());
		sort(secondWord.begin(), secondWord.end());

		if (IsAnagram(firstWord, secondWord) == true)
		{
			minSum = 0;
		}
		else
		{
			RemoveEqualSymbols(firstWord, secondWord);
			minSum = FindMinSum(firstWord, secondWord);
		}
		cout << minSum << endl;
	}

	return 0;
}