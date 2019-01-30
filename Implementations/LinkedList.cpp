#include <cmath>
#include <cstdio>
#include <vector>
#include<string>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int value;
	Node*next;
	Node(int v, Node*n)
	{
		this->value = v;
		this->next = n;
	}
};

class LinkedList {
public:
	LinkedList()
	{
		this->start = NULL;
		this->size = 0;
	}
	void DeleteFirst()
	{
		if (this->size > 0)
		{
			Node* temp = this->start;
			this->start = this->start->next;
			this->size--;
			delete temp;
		}
	}
	Node* FindElement(int index)
	{
		if (index >= 0 && index <= this->size)
		{
			Node* temp = this->start;
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
			return temp;
		}
		return nullptr;
	};
	void add(int val, int pos)
	{
		if (pos < 0 || pos > size) {
			cout << "add_last";
			pos = size;
		}

		if (!this->start || pos == 0) {
			this->start = new Node(val, this->start);
		}
		else {
			Node * cur = this->start;

			while (pos > 1) {
				pos--;
				cur = cur->next;
			}

			cur->next = new Node(val, cur->next);
		}

		this->size++;
	}

	void remove(int pos) {
		if (pos < 0 || pos >= size) {
			cout << "remove_failed";
			return;
		}

		Node * prev = nullptr;
		Node * cur = this->start;

		while (pos > 0) {
			prev = cur;
			cur = cur->next;
			pos--;
		}

		if (prev == nullptr) {
			prev = this->start->next;
			delete this->start;
			this->start = prev;
		}
		else {
			prev->next = cur->next;
			delete cur;
		}

		this->size--;
	}

	void reverse() {
		Node*current = this->start;
		Node*previous = NULL;
		Node*next = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		this->start = previous;
	}

	void remove_all(int val) {
		Node * cur = this->start;

		while (cur && cur->next) {
			if (cur->next->value == val) {
				Node * temp = cur->next->next;
				delete cur->next;
				cur->next = temp;
				size--;
			}
			else {
				cur = cur->next;
			}
		}

		if (this->start && this->start->value == val) {
			Node * temp = this->start->next;
			delete this->start;
			this->start = temp;
			this->size--;
		}
	}

	void group(int a, int b) {
		if (a < 0 || b >= this->size || b < a) {
			cout << "fail_grouping";
		}
		else {
			int elementsToDelete = b - a;
			Node * cur = this -> start;

			while (a > 0) {
				cur = cur->next;
				a--;
			}

			while (elementsToDelete > 0) {
				Node * temp = cur->next->next;
				cur->value += cur->next->value;
				delete cur->next;
				cur->next = temp;

				elementsToDelete--;
				this->size--;
			}
		}
	}

	void count(int val) {
		Node*current = this->start;
		int repeatNum = 0;
		while (current != NULL)
		{
			if (current->value == val)
			{
				repeatNum++;
			}
			current = current->next;
		}
		cout << repeatNum;
	}

	void is_palindrome() {
		bool isPalindrome = true;
		std::vector<int>numbers;
		Node*current = this->start;
		while (current != NULL)
		{
			numbers.push_back(current->value);
			current = current->next;
		}
		int lastElem = numbers.size() - 1;
		for (int i = 0; i < numbers.size() / 2; i++)
		{
			if (numbers[i] != numbers[lastElem])
			{
				isPalindrome = false;
				break;
			}
			lastElem--;
		}
		if (isPalindrome == true)
		{
			std::cout << "true";
		}
		else
		{
			std::cout << "false";
		}

	}

	void print() {
		Node*current = this->start;
		while (current != NULL)
		{
			cout << current->value << "#";
			current = current->next;
		}
	}
	~LinkedList() {
		Destroy();
	}

private:
	void Destroy()
	{
		while (this->size > 0)
		{
			this->DeleteFirst();
		}
	};
	Node * start;
	int size;
};

int main() {
	/*************template/*************/
	int cases;
	std::cin >> cases;
	for (int i = 0; i < cases; i++) {
		LinkedList ll;
		int ops;
		std::string op;
		std::cin >> ops;
		for (int j = 0; j < ops; j++) {
			std::cin >> op;

			if (op == "count") {
				int arg1;
				std::cin >> arg1;
				ll.count(arg1);
			}

			if (op == "add") {
				int arg1, arg2;
				std::cin >> arg1 >> arg2;
				ll.add(arg1, arg2);
			}

			if (op == "print") {
				ll.print();
			}

			if (op == "remove") {
				int arg1;
				std::cin >> arg1;
				ll.remove(arg1);
			}

			if (op == "reverse") {
				ll.reverse();
			}

			if (op == "remove_all") {
				int arg1;
				std::cin >> arg1;
				ll.remove_all(arg1);
			}

			if (op == "group") {
				int arg1, arg2;
				std::cin >> arg1 >> arg2;
				ll.group(arg1, arg2);
			}

			if (op == "is_palindrom") {
				ll.is_palindrome();
			}
		}

		std::cout << std::endl;

	}
	return 0;
}