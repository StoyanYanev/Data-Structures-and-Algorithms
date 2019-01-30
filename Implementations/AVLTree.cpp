#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
	double value;
	Node *left;
	Node *right;

	Node(double value, Node *left, Node *right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
};

class AVLTree
{
private:
	Node * root;

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}

	int Height(Node* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		else
		{
			int leftDepth = Height(node->left);
			int rightDepth = Height(node->right);
			if (leftDepth > rightDepth)
			{
				return (leftDepth + 1);
			}
			else
			{
				return (rightDepth + 1);
			}
		}
	}

	Node* SingleRightRotate(Node* &node)
	{
		Node* t = node->left;
		node->left = t->right;
		t->right = node;
		return t;
	}

	Node* SingleLeftRotate(Node* &node)
	{
		Node* t = node->right;
		node->right = t->left;
		t->left = node;
		return t;
	}

	Node* DoubleLeftRotate(Node* &node)
	{
		node->right = SingleRightRotate(node->right);
		return SingleLeftRotate(node);
	}

	Node* DoubleRightRotate(Node* &node)
	{
		node->left = SingleLeftRotate(node->left);
		return SingleRightRotate(node);
	}

	Node* addNewNode(Node* node, double value)
	{
		if (node == NULL)
		{
			node = new Node(value, NULL, NULL);
		}
		else if (value < node->value)
		{
			node->left = addNewNode(node->left, value);
			if (Height(node->left) - Height(node->right) == 2)
			{
				if (value < node->left->value)
				{
					node = SingleRightRotate(node);
				}
				else
				{
					node = DoubleRightRotate(node);
				}
			}
		}
		else if (value > node->value)
		{
			node->right = addNewNode(node->right, value);
			if (Height(node->right) - Height(node->left) == 2)
			{
				if (value > node->right->value)
				{
					node = SingleLeftRotate(node);
				}
				else
				{
					node = DoubleLeftRotate(node);
				}
			}
		}
		return node;
	}

	Node* FindMin(Node* node)
	{
		if (node == NULL)
		{
			return NULL;
		}
		else if (node->left == NULL)
		{
			return node;
		}
		else
		{
			return FindMin(node->left);
		}
	}

	Node* DeleteElement(Node*node, double value)
	{
		Node* temp;

		if (node == NULL)
		{
			return NULL;
		}
		else if (value < node->value)
		{
			node->left = DeleteElement(node->left, value);

		}
		else if (value > node->value)
		{
			node->right = DeleteElement(node->right, value);

		}
		else if (node->left && node->right)
		{
			temp = FindMin(node->right);
			node->value = temp->value;
			node->right = DeleteElement(node->right, node->value);
		}
		else
		{
			temp = node;
			if (node->left == NULL)
			{
				node = node->right;
			}
			else if (node->right == NULL)
			{
				node = node->left;
			}
			delete temp;
		}
		if (node == NULL)
		{
			return node;
		}
		if (Height(node->left) - Height(node->right) == 2)
		{
			if (Height(node->left->left) - Height(node->left->right) == 1)
			{
				return SingleLeftRotate(node);
			}
			else
			{
				return DoubleLeftRotate(node);
			}
		}
		else if (Height(node->right) - Height(node->left) == 2)
		{
			if (Height(node->right->right) - Height(node->right->left) == 1)
			{
				return SingleRightRotate(node);
			}
			else
			{
				return DoubleRightRotate(node);
			}
		}
		return node;
	}

public:
	AVLTree()
	{
		root = NULL;
	};

	void add(double value)
	{
		if (containsRecursive(root, value) == true)
		{
			cout << value << " already added" << endl;
		}
		else
		{
			root = addNewNode(root, value);
		}
	};

	void remove(double value)
	{
		if (containsRecursive(root, value) == false)
		{
			cout << value << " not found to remove" << endl;
		}
		else
		{
			root = DeleteElement(root, value);
		}

	};

	bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	};

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
		cout << endl;
	};
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
	cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}

	return 0;
}