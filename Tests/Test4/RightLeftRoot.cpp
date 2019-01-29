#include <iostream>
#include<vector>
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
	void print(Node *root, vector<int>& allNodes) {
		if (root != NULL)
		{
			print(root->rightNode, allNodes);
			print(root->leftNode, allNodes);
			allNodes.push_back(root->data);
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

	vector<int>allNodes;
	myTree.print(root, allNodes);
	for (int i = 0; i < allNodes.size(); i++)
	{
		if (i + 1 == allNodes.size())
		{
			cout << allNodes[i];
		}
		else
		{
			cout << allNodes[i] << ";";
		}
	}

	myTree.Delete(root);

	return 0;
}