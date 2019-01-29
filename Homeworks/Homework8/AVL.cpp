#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Node
{
	double value;
	int height;
	Node *left;
	Node *right;

	Node(double value, Node *left, Node *right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
		height = 1;
	}
};

class AVLTree
{
private:
	Node * root;

	void Destroy(Node* node)
	{
		if (node != NULL)
		{
			Destroy(node->left);
			Destroy(node->right);
			delete node;
		}
	};
	
	bool ContainsRecursive(Node *current, double value)
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
			return ContainsRecursive(current->left, value);
		}
		else
		{
			return ContainsRecursive(current->right, value);
		}
	}

	void PrintRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		PrintRecursive(current->left);
		cout << current->value << " ";
		PrintRecursive(current->right);
	}

	int Height(Node* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		return node->height;
	}

	int GetBalance(Node* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		return (Height(node->left) - Height(node->right));
	}

	Node* RightRotate(Node* node)
	{
		Node* x = node->left;
		Node* t = x->right;

		x->right = node;
		node->left = t;

		node->height = 1 + std::max(Height(node->left), Height(node->right));
		x->height = 1 + std::max(Height(x->left), Height(x->right));
		return x;
	}

	Node* LeftRotate(Node* node)
	{
		Node* y = node->right;
		Node* t = y->left;

		y->left = node;
		node->right = t;

		node->height = 1 + std::max(Height(node->left), Height(node->right));
		y->height = 1 + std::max(Height(y->left), Height(y->right));

		return y;
	}

	Node* AddNewNode(Node* node, double value)
	{
		if (node == NULL)
		{
			node = new Node(value, NULL, NULL);
		}
		if (value < node->value)
		{
			node->left = AddNewNode(node->left, value);
		}
		else if (value > node->value)
		{
			node->right = AddNewNode(node->right, value);
		}
		else
		{
			return node;
		}

		node->height = 1 + std::max(Height(node->left), Height(node->right));

		int balance = GetBalance(node);

		if (balance > 1 && value < node->left->value)
		{
			return RightRotate(node);
		}
		if (balance < -1 && (value > node->right->value))
		{
			return LeftRotate(node);
		}
		if (balance > 1 && (value > node->left->value))
		{
			node->left = LeftRotate(node->left);
			return RightRotate(node);
		}
		if (balance < -1 && (value < node->right->value))
		{
			node->right = RightRotate(node->right);
			return LeftRotate(node);
		}

		return node;
	}

	Node* FindMin(Node* node)
	{
		Node* current = node;

		while (current->left != NULL)
		{
			current = current->left;
		}

		return current;
	}

	Node* DeleteElement(Node* node, double value)
	{
		if (node == NULL)
		{
			return root;
		}
		if (value < node->value)
		{
			node->left = DeleteElement(node->left, value);
		}
		else if (value > node->value)
		{
			node->right = DeleteElement(node->right, value);
		}
		else
		{
			Node* temp;
			if ((node->left == NULL) || (node->right == NULL))
			{
				if (node->left != NULL)
				{
					temp = node->left;
				}
				else
				{
					temp = node->right;
				}
				if (temp == NULL)
				{
					temp = node;
					node = NULL;
				}
				else
				{
					*node = *temp;
					delete temp;
				}
			}
			else
			{
				temp = FindMin(node->right);
				node->value = temp->value;
				node->right = DeleteElement(node->right, temp->value);
			}
		}
		if (node == NULL)
		{
			return node;
		}
		node->height = 1 + std::max(Height(node->left), Height(node->right));
		int balance = GetBalance(node);
		int leftBlance = GetBalance(node->left);
		int rightBalance = GetBalance(node->right);

		if (balance > 1 && leftBlance >= 0)
		{
			return RightRotate(node);
		}
		if (balance > 1 && leftBlance < 0)
		{
			node->left = LeftRotate(node->left);
			return RightRotate(node);
		}

		if (balance < -1 && rightBalance <= 0)
		{
			return LeftRotate(node);
		}
		if (balance < -1 && rightBalance > 0)
		{
			node->right = RightRotate(node->right);
			return LeftRotate(node);
		}

		return node;
	}
public:
	AVLTree()
	{
		root = NULL;
	};

	void Add(double value)
	{
		if (ContainsRecursive(root, value) == true)
		{
			cout << value << " already added" << endl;
		}
		else
		{
			root = AddNewNode(root, value);
		}
	};

	void Remove(double value)
	{
		if (ContainsRecursive(root, value) == false)
		{
			cout << value << " not found to remove" << endl;
		}
		else
		{
			root = DeleteElement(root, value);
		}

	};

	bool Contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return ContainsRecursive(root, value);
	};

	void Print()
	{
		if (root == NULL)
		{
			return;
		}

		PrintRecursive(root);
		cout << endl;
	};
	~AVLTree()
	{
		Destroy(root);
	}
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
	cout << fixed;

	for (int i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.Add(number);
		}
		else if (operation == "remove")
		{
			tree.Remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.Contains(number))
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
			tree.Print();
		}
	}

	return 0;
}