#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_NUMBER = 1234;

struct Pair
{
	int first;
	int second;
};

struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
public:
	LinkedList()
	{
		m_head = NULL;
		m_tail = NULL;
	};
	void Add(int data)
	{
		Node* temp = new Node;
		temp->data = data;
		temp->next = NULL;
		if (m_head == NULL)
		{
			m_head = temp;
			m_tail = temp;
			temp = NULL;
		}
		else
		{
			m_tail->next = temp;
			m_tail = temp;
		}
	};
	void NumberOfPairs(std::vector<int>& elements, std::vector<Pair> &pair)
	{
		Node* current = m_head;
		Pair p;
		while (current != NULL)
		{
			if (IsContained(elements, 0, elements.size() - 1, current->data) == true)
			{
				p.first = current->data;
				current = current->next;
				if (current != NULL)
				{
					if (IsContained(elements, 0, elements.size() - 1, current->data) == true)
					{
						p.second = current->data;
						pair.push_back(p);
					}
				}
			}
			else
			{
				current = current->next;
			}
		}
	};
	~LinkedList()
	{
		Node* current = m_head;
		while (m_head)
		{
			m_head = m_head->next;
			delete current;
			current = m_head;
		}
	};

private:
	/*Binary search*/
	bool IsContained(std::vector<int>& elements, long long start, long long end, int number)
	{
		if (start <= end)
		{
			long long middle = start + (end - start) / 2;
			if (elements[middle] == number)
			{
				return true;
			}
			else if (elements[middle] > number)
			{
				return IsContained(elements, start, middle - 1, number);
			}
			else
			{
				return IsContained(elements, middle + 1, end, number);
			}
		}
		return false;
	};

	Node * m_head;
	Node* m_tail;
};

int main()
{
	long long n;
	std::cin >> n;

	int currentNumber;
	LinkedList list;
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> currentNumber;
		list.Add(currentNumber);
	}

	int p;
	std::cin >> p;
	long long curr;
	std::vector<int> elements;

	for (int i = 0; i < p; i++)
	{
		std::cin >> curr;
		if (curr <= MAX_NUMBER)
		{
			elements.push_back(curr);
		}
	}

	std::sort(elements.begin(), elements.end());

	std::vector<Pair> pair;
	list.NumberOfPairs(elements, pair);
	long long numberOfPairs = pair.size();

	for (int i = 0; i < pair.size(); i++)
	{
		for (int j = i + 1; j < pair.size(); j++)
		{
			if ((pair[i].first == pair[j].first && pair[i].second == pair[j].second) || ((pair[i].first == pair[j].second && pair[i].second == pair[j].first)))
			{
				if (numberOfPairs - 1 <= 0)
				{
					numberOfPairs = 1;
					break;
				}
				numberOfPairs--;
			}
		}
	}
	std::cout << numberOfPairs << std::endl;

	return 0;
}