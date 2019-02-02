#include <iostream>

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
	};

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
				if (key >= current->key)
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
			if (key >= parent->key)
			{
				parent->right = new Node(key);
			}
			else
			{
				parent->left = new Node(key);
			}
		}
	};

	void Delete(int val)
	{
		DeleteElement(this->root, val);
	};

	void PrintPrefix()
	{
		Prefix(this->root);
	};

	void PrintInfix()
	{
		Infix(this->root);
	};

	void PrintPostfix()
	{
		Postfix(this->root);
	};

	bool IsEmpty()
	{
		if (this->root == NULL)
		{
			return true;
		}
		return false;
	}

	int GetHeight()
	{
		return Height(this->root);
	};

	int CountAllNode()
	{
		return AllNodes(this->root);
	};

	int CountAllLeaves()
	{
		return AllLeaves(this->root);
	};

	bool Search(int key)
	{
		return FindElement(this->root, key);
	};

	int SumOfAllNodes()
	{
		return SumOfNodes(this->root);
	};

	int GetMinNode()
	{
		if (IsEmpty() == false)
		{
			Node* current = this->root;

			while (current->left != NULL)
			{
				current = current->left;
			}
			return current->key;
		}
		return -1;
	};

	int GetMaxNode()
	{
		if (IsEmpty() == false)
		{
			Node* current = this->root;

			while (current->right != NULL)
			{
				current = current->right;
			}
			return current->key;
		}
		return -1;
	};

	void PrintLevelsOfAllNodes()
	{
		int h = GetHeight();
		for (int i = 1; i <= h + 1; i++)
		{
			Levels(root, i);
		}
	}

	void PrintAllEvenNodes()
	{
		EvenNodes(root);
	}

	void PrintAllOddNodes()
	{
		OddNodes(root);
	}

	~Tree() { Destroy(this->root); };

private:
	Node* MinValueNode(Node*node)
	{
		Node*current = node;
		while (current->left != NULL)
		{
			current = current->left;
			return current;
		}
	}
	Node * DeleteElement(Node* node, int val)
	{
		if (IsEmpty() == false)
		{
			if (FindElement(node, val) == true)
			{
				if (val < node->key)
				{
					node->left = DeleteElement(node->left, val);
				}
				else if (val > node->key)
				{
					node->right = DeleteElement(node->right, val);
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
						node->right = DeleteElement(node->right, temp->key);
					}
				}
			}
		}
		return node;
	}

	void Prefix(Node* node) // root left right
	{
		if (node != NULL)
		{
			std::cout << node->key << " ";
			Prefix(node->left);
			Prefix(node->right);
		}
	};

	void Infix(Node* node) // left root right
	{
		Prefix(node->left);
		std::cout << node->key << " ";
		Prefix(node->right);
	};

	void Postfix(Node* node)// left right root
	{
		Prefix(node->left);
		Prefix(node->right);
		std::cout << node->key << " ";
	};

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
	};

	int AllNodes(Node* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		else
		{
			int count = 1;
			if (node->left != NULL)
			{
				count += AllNodes(node->left);
			}
			if (node->right != NULL)
			{
				count += AllNodes(node->right);
			}
			return count;
		}
	};

	int AllLeaves(Node* node)
	{
		if (node->left == NULL && node->right == NULL)
		{
			return 1;
		}
		else
		{
			int count = 0;
			if (node->left != NULL)
			{
				count += AllLeaves(node->left);
			}
			if (node->right != NULL)
			{
				count += AllLeaves(node->right);
			}
			return count;
		}
	};

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

	int SumOfNodes(Node* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		else
		{
			int sum = 0;
			sum += node->key + SumOfNodes(node->left);
			sum += SumOfNodes(node->right);
			return sum;
		}
	};
	void Destroy(Node* node)
	{
		if (node != NULL)
		{
			Destroy(node->left);
			Destroy(node->right);
			delete node;
		}
	};

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
	};
	
	void EvenNodes(Node* node)
	{
		if (node != NULL)
		{
			EvenNodes(node->left);
			if (node->key % 2 == 0)
			{
				std::cout << node->key << " ";
			}
			EvenNodes(node->right);
		}
	};

	void OddNodes(Node* node)
	{
		if (node != NULL)
		{
			OddNodes(node->left);
			if (node->key % 2 != 0)
			{
				std::cout << node->key << " ";
			}
			OddNodes(node->right);
		}
	};

	Node* root;
};

int main()
{
	Tree tree;
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(2);
	tree.Insert(4);
	tree.Insert(7);
	tree.Insert(6);
	tree.Insert(8);

	tree.PrintLevelsOfAllNodes();
	std::cout << std::endl;

	tree.PrintPrefix();
	std::cout << std::endl;

	tree.PrintInfix();
	std::cout << std::endl;

	tree.PrintPostfix();
	std::cout << std::endl;

	tree.PrintPrefix();
	std::cout << std::endl;

	tree.Delete(4);
	//tree.Delete(50);

	tree.PrintPrefix();
	std::cout << std::endl;

	std::cout << tree.GetHeight() << std::endl;

	std::cout << tree.CountAllNode() << std::endl;

	std::cout << tree.CountAllLeaves() << std::endl;

	std::cout << tree.Search(7) << std::endl;

	std::cout << tree.Search(50) << std::endl;

	std::cout << tree.SumOfAllNodes() << std::endl;

	std::cout << tree.GetMinNode() << std::endl;

	std::cout << tree.GetMaxNode() << std::endl;

	tree.PrintAllEvenNodes();
	std::cout << std::endl;

	tree.PrintAllOddNodes();
	std::cout << std::endl;

	return 0;
}
