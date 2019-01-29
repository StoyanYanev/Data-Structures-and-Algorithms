#include<iostream>
#include<map>

using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
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
				cur = insert(root->left, data);
				root->left = cur;
			}
			else {
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}
	void printTop(Node *root, int dist, int level, map<int, pair<int, int>> &map)
	{
		if (root == nullptr)
			return;

		if (map.find(dist) == map.end() || level < map[dist].second)
		{

			map[dist] = { root->data, level };
		}

		printTop(root->left, dist - 1, level + 1, map);

		printTop(root->right, dist + 1, level + 1, map);
	}

	void topView(Node * root) {

		map<int, pair<int, int>> map;


		printTop(root, 0, 0, map);


		for (auto it : map)
			cout << it.second.first << " ";
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

	myTree.topView(root);

	return 0;
}