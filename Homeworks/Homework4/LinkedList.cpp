#include<iostream>

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
	int GetMin()
	{
		Node* temp = m_head;
		int min = temp->data;
		while (temp != NULL)
		{
			if (min > temp->data)
			{
				min = temp->data;
			}
			temp = temp->next;
		}
		return min;
	};
	int GetMax()
	{
		Node* temp = m_head;
		int max = temp->data;
		while (temp != NULL)
		{
			if (max < temp->data)
			{
				max = temp->data;
			}
			temp = temp->next;
		}
		return max;
	};
	long long GetSum()
	{
		Node* temp = m_head;
		long long sum = 0;
		while (temp != NULL)
		{
			sum += temp->data;
			temp = temp->next;
		}
		return sum;
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

	Node * m_head;
	Node* m_tail;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	LinkedList list;
	int num;
	while (std::cin >> num)
	{
		list.Add(num);
	}

	std::cout << list.GetMin() << " " << list.GetMax() << " " << list.GetSum() << std::endl;

	return 0;
}