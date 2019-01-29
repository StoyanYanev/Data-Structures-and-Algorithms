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

    Node* Insert(Node* root, int data)
    {
        if (root == NULL) {
            return new Node(data);
        }
        else
        {
            Node* current;
            if (data < root->key)
            {
                current = Insert(root->left, data);
                root->left = current;
            }
            else
            {
                current = Insert(root->right, data);
                root->right = current;
            }

            return root;
        }
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

     void FindNodeOfCurrentLevel(Node* node, int level, long long &sum, int& count)
    {
        if (node == NULL)
        {
            return;
        }
        if (level == 1)
        {
            sum += node->key;
            count++;
        }
        else if (level > 1)
        {
            FindNodeOfCurrentLevel(node->left, level - 1, sum, count);
            FindNodeOfCurrentLevel(node->right, level - 1, sum, count);
        }
    };

    void SumOfLevels(Node* root)
    {
        long long sum = 0;
        int h = Height(root);
        int count = 0;
        for (int i = 1; i <= h + 1; i++)
        {
            FindNodeOfCurrentLevel(root, i, sum, count);
            if (count != 0)
            {
                printf("%.2f", (double)sum / count);
                std::cout << std::endl;
            }
            else
            {
                std::cout << sum << std::endl;
            }
            sum = 0;
            count = 0;
        }
    };

    
int main()
{
    Node* root = NULL;
    int n;
    int node;
    std::cin >> n;

    while (n > 0)
    {
        std::cin >> node;
        root = Insert(root,node);
        n--;
    }

    SumOfLevels(root);
	delete[] root;
    return 0;
}