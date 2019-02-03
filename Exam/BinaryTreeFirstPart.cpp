#include<iostream>
#include<string>

using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;

	Node(int val)
	{
		key = val;
		left = NULL;
		right = NULL;
	}
};

class Tree
{
public:
	Tree()
	{
		root = NULL;
	}

	void Insert(int key)
	{
		if (IsEmpty() == true)
		{
			this->root = new Node(key);
		}
		else
		{
			Node* current = this->root;
			Node* parent = 0;
			while (current != NULL)
			{
				parent = current;
				if (current->key == key)
				{
					parent = NULL;
					return;
				}
				if (key > current->key)
				{
					current = current->right;
				}
				else
				{
					current = current->left;
				}
			}
			if (parent == NULL)
			{
				return;
			}
			if (key > parent->key)
			{
				parent->right = new Node(key);
			}
			else if (parent->key > key)
			{
				parent->left = new Node(key);
			}
		}
	}

	bool IsEmpty()
	{
		if (this->root == NULL)
		{
			return true;
		}
		return false;
	}

	void Print()
	{
		RootLeftRight(root);
	}

	~Tree()
	{
		Destroy(root);
	}

private:
	void RootLeftRight(Node* node)
	{
		if (node != NULL)
		{
			std::cout << node->key << " ";
			RootLeftRight(node->left);
			RootLeftRight(node->right);
		}
	}

	void Destroy(Node* node)
	{
		if (node != NULL)
		{
			Destroy(node->left);
			Destroy(node->right);
			delete node;
		}
	}

	Node* root;
};

int main()
{
	int n;
	cin >> n;

	Tree root;
	string input;
	int x;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input[0] == 'a')
		{
			cin >> x;
			root.Insert(x);
		}
		else if (input == "print")
		{
			root.Print();
		}
	}

	return 0;
}