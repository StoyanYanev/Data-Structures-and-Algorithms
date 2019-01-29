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
	/*
	* Complete the function below.
	*/
	void leaves(Node *root, int &sum) {
		if (root != NULL)
		{
			if (root->rightNode == NULL && root->leftNode == NULL)
			{
				if (root->data % 2 != 0)
				{
					sum += root->data;
				}
			}
			leaves(root->leftNode, sum);
			leaves(root->rightNode, sum);
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

	int sum = 0;
	myTree.leaves(root, sum);
	cout << sum << endl;
	myTree.Delete(root);

	return 0;
}
