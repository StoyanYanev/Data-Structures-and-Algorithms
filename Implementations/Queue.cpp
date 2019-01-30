#include <iostream>

using namespace std;

class Queue
{
public:
	Queue()
	{
		size = 0;
		head = tail = nullptr;
	}

	void Enqueue(int n)
	{
		Node *newElement = new Node(n);
		if (size == 0)
		{
			head = tail = newElement;
		}
		else
		{
			tail = tail->next = newElement;
		}
		size++;
	}

	void Dequeue()
	{
		if (IsEmpty() == false)
		{
			if (size == 1)
			{
				delete head;
				head = tail = nullptr;
			}
			else
			{
				Node* element = head;
				head = head->next;
				delete element;
			}
			size--;
		}
	}

	bool IsEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}

	int GetSize()
	{
		return size;
	}

	int Front()
	{
		if (IsEmpty() == false)
		{
			return head->data;
		}
		return -1;
	}

	void Display()
	{
		if (head == NULL)
		{
			return;
		}
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	~Queue()
	{
		while (head != nullptr)
		{
			Node* element = head;
			head = head->next;
			delete element;
		}
		size = 0;
		head = tail = nullptr;
	}

private:
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
		Node(int value)
		{
			data = value;
			next = prev = nullptr;
		}
	};
	Node* head;
	Node* tail;
	int size;
};

int main()
{
	Queue q;
	q.Enqueue(5);
	q.Enqueue(6);
	q.Enqueue(8);
	q.Enqueue(2);
	q.Enqueue(1);

	std::cout << "First element: " << q.Front() << std::endl;
	std::cout << "Print all elements" << std::endl;
	q.Display();

	std::cout << "Remove first" << std::endl;
	q.Dequeue();

	std::cout << "Print all elements" << std::endl;
	q.Display();

	return 0;
}