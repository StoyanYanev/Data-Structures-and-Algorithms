#include<iostream>
#include<queue>
#include<vector>

using namespace std;

long long FindSumOfAllPositiveElements(priority_queue<int, vector<int>>num)
{
	long long sum = 0;
	while (num.empty() == false)
	{
		sum += num.top();
		num.pop();
	}
	return sum;
}

long long FindSumOfAllNegativeElements(priority_queue<int, vector<int>, greater<int>>num)
{
	long long sum = 0;
	while (num.empty() == false)
	{
		sum += num.top();
		num.pop();
	}
	return sum;
}

long long FindSumOfAllPositiveGroups(priority_queue<int, vector<int>>num)
{
	long long allSum = 0;
	long long currentSum = 0;
	long long product = 0;
	int firstElement = 0;
	int secondElement = 0;
	while (num.empty() == false)
	{
		if (num.size() >= 2)
		{
			firstElement = num.top();
			num.pop();
			secondElement = num.top();
			num.pop();
			currentSum = firstElement + secondElement;
			product = firstElement * secondElement;
			if (currentSum > product)
			{
				allSum += currentSum;
			}
			else
			{
				allSum += product;
			}
		}
		else
		{
			allSum += num.top();
			num.pop();
		}
	}
	return allSum;
}

long long FindSumOfAllNegativeGroups(priority_queue<int, vector<int>, greater<int>>num)
{
	long long allSum = 0;
	long long currentSum = 0;
	long long product = 0;
	int firstElement = 0;
	int secondElement = 0;
	while (num.empty() == false)
	{
		if (num.size() >= 2)
		{
			firstElement = num.top();
			num.pop();
			secondElement = num.top();
			num.pop();
			currentSum = firstElement + secondElement;
			product = firstElement * secondElement;
			if (currentSum > product)
			{
				allSum += currentSum;
			}
			else
			{
				allSum += product;
			}
		}
		else
		{
			allSum += num.top();
			num.pop();
		}
	}

	return allSum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int n;
	int currentNumber;
	long long sumOfAllElements = 0;
	long long sumOfAllGroups = 0;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		priority_queue<int, vector<int>>positiveNumbers;
		priority_queue<int, vector<int>, greater<int>>negativeNumbers;
		for (int i = 0; i < n; i++)
		{
			cin >> currentNumber;
			if (currentNumber > 0)
			{
				positiveNumbers.push(currentNumber);
			}
			else
			{
				negativeNumbers.push(currentNumber);
			}
		}
		sumOfAllElements = FindSumOfAllPositiveElements(positiveNumbers) + FindSumOfAllNegativeElements(negativeNumbers);
		sumOfAllGroups = FindSumOfAllPositiveGroups(positiveNumbers) + FindSumOfAllNegativeGroups(negativeNumbers);
		if (sumOfAllElements > sumOfAllGroups)
		{
			cout << sumOfAllElements << endl;
		}
		else
		{
			cout << sumOfAllGroups << endl;
		}
		sumOfAllElements = 0;
		sumOfAllGroups = 0;
	}

	return 0;
}