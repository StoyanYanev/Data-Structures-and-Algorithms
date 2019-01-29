#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node *leftNode;
	Node *rightNode;
	Node(int d) {
		data = d;
		leftNode = NULL;
		rightNode = NULL;
	}
};

class Solution {
public:
	Node * insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else {
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->leftNode, data);
				root->leftNode = cur;
			}
			else {
				cur = insert(root->rightNode, data);
				root->rightNode = cur;
			}

			return root;
		}
	}
	int Height(Node* root)
	{
		if (root != NULL)
		{
			int left = Height(root->leftNode);
			int right = Height(root->rightNode);
			if (left > right)
			{
				return (left + 1);
			}
			else
			{
				return (right + 1);
			}
		}
		else
		{
			return 0;
		}
	}

	void Levels(Node *root, int level, int &count)
	{
		if (root == NULL)
		{
			return;
		}
		else if (level == 1)
		{
			count++;
		}
		else
		{
			Levels(root->leftNode, level - 1, count);
			Levels(root->rightNode, level - 1, count);
		}
	}
	void count(Node *root) {
		int h = Height(root) + 1;
		int count = 0;
		for (int i = 1; i < h; i++)
		{
			Levels(root, i, count);
			if (i + 1 == h)
			{
				cout << count;
			}
			else
			{
				cout << count << ";";
			}
			count = 0;
		}
	}
	void Delete(Node* root)
	{
		if (root == NULL) return;

		Delete(root->leftNode);
		Delete(root->rightNode);
		delete root;
	}
}; //End of Solution

int main() {

	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	myTree.count(root);

	myTree.Delete(root);

	return 0;
}