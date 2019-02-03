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

	void Remove(int val)
	{
		RemoveElement(this->root, val);
	}

	bool IsEmpty()
	{
		if (this->root == NULL)
		{
			return true;
		}
		return false;
	}

	void PrintOddLevels()
	{
		int h = Height(root);
		for (int i = 1; i <= h + 1; i += 2)
		{
			Levels(root, i);
		}
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

	int Height(Node* node)
	{
		if (node == NULL)
		{
			return -1;
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

	void Levels(Node* node, int level)
	{
		if (node == NULL)
		{
			return;
		}
		else if (level == 1)
		{
			std::cout << node->key << " ";
		}
		else
		{
			Levels(node->left, level - 1);
			Levels(node->right, level - 1);
		}
	}

	Node* MinValueNode(Node*node)
	{
		Node*current = node;
		while (current->left != NULL)
		{
			current = current->left;
		}
		return current;
	}

	bool FindElement(Node* node, int val)
	{
		if (node != NULL)
		{
			if (node->key == val)
			{
				return true;
			}
			else if (val <= node->key)
			{
				return FindElement(node->left, val);
			}
			else if (val > node->key)
			{
				return FindElement(node->right, val);
			}
		}
		return false;
	}

	Node* RemoveElement(Node* &node, int val)
	{
		if (IsEmpty() == false)
		{
			if (FindElement(node, val) == true)
			{
				if (val < node->key)
				{
					node->left = RemoveElement(node->left, val);
				}
				else if (val > node->key)
				{
					node->right = RemoveElement(node->right, val);
				}
				else
				{
					if (node->left == NULL && node->right == NULL)
					{
						delete node;
						node = NULL;
					}
					else if (node->left == NULL)
					{
						Node* temp = node;
						node = node->right;
						delete temp;
					}
					else if (node->right == NULL)
					{
						Node* temp = node;
						node = node->left;
						delete temp;
					}
					else
					{
						Node* temp = MinValueNode(node->right);
						node->key = temp->key;
						node->right = RemoveElement(node->right, temp->key);
					}
				}
			}
		}
		return node;
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
	ios_base::sync_with_stdio(false);
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
		else if (input[0] == 'r')
		{
			cin >> x;
			root.Remove(x);
		}
		else if (input == "print")
		{
			root.Print();
		}
		else
		{
			root.PrintOddLevels();
		}
	}

	return 0;
}