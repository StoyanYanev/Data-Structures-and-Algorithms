#include <iostream>

using namespace std;

class Stack
{
public:
	Stack()
	{
		top = NULL;
		size = 0;
	}
	void Push(int element)
	{
		Node* newTop = new Node();
		newTop->data = element;
		newTop->next = top;

		top = newTop;
		size++;
	}
	void Pop()
	{
		if (top == NULL)
		{
			return;
		}

		Node *nextTop = top->next;
		delete top;

		top = nextTop;
		size--;
	}
	int Peek()
	{
		if (top != NULL)
		{
			return top->data;
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
	void Print()
	{
		Node*current = top;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	~Stack()
	{
		while (top != NULL)
		{
			Node* element = top;
			top = top->next;
			delete element;
		}
		size = 0;
		top = NULL;
	}
private:
	struct Node
	{
		int data;
		Node *next;
	};

	Node * top;
	int size;
};

int main()
{
	Stack stack;
	stack.Push(5);
	stack.Push(6);
	stack.Push(7);
	stack.Push(8);

	std::cout << "Print all elements" << std::endl;
	stack.Print();

	std::cout << "The last element: " << stack.Peek() << std::endl;

	std::cout << "Remove the last element and print the others" << std::endl;
	stack.Pop();
	stack.Print();

	return 0;
}