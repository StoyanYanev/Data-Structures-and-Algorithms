#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int>&numbers, int l, int m, int r);
void MergeSort(vector<int>&numbers, int l, int r);

int main()
{
	int n;
	cin >> n;

	vector<int>numbers;
	int currentNumber;
	for (int i = 0; i < n; i++)
	{
		cin >> currentNumber;
		numbers.push_back(currentNumber);
	}

	MergeSort(numbers, 0, numbers.size() - 1);

	return 0;
}

void MergeSort(vector<int>& numbers, int l, int r)
{
	if (l < r)
	{
		int m = l + (r-l) / 2;

		MergeSort(numbers, l, m);
		MergeSort(numbers, m + 1, r);
		Merge(numbers, l, m, r);
	}
		
}

void Merge(vector<int>& numbers, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<int>L(n1);
	vector<int>R(n2);

	for (int i = 0; i < n1; i++)
	{
		L[i] = numbers[l + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = numbers[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			numbers[k] = L[i];
			i++;
		}
		else
		{
			numbers[k] = R[j];
			j++;
		}
		cout << numbers[k] << " ";
		k++;
	}

	while (i < n1)
	{
		numbers[k] = L[i];
		cout << numbers[k] << " ";
		i++;
		k++;
	}

	while (j < n2)
	{
		numbers[k] = R[j];
		cout << numbers[k] << " ";
		j++;
		k++;
	}
}