#include <iostream>

struct HashNode
{
	long long val;
	HashNode* next;
	HashNode(int v)
	{
		val = v;
		next = NULL;
	}
};

class Hash
{
public:
	Hash(int n)
	{
		size = n;
		numberOfElements = 0;
		hash = new HashNode*[size];
		for (int i = 0; i < size; i++)
		{
			hash[i] = NULL;
		}
	}

	void Insert(int val)
	{
		int index = HashFunction(val);

		if (Contains(val) == false)
		{
			if (hash[index] != NULL)
			{
				HashNode* current = hash[index];
				while (current->next != NULL)
				{
					current = current->next;
				}
				current->next = new HashNode(val);
			}
			else
			{
				hash[index] = new HashNode(val);
			}
			numberOfElements++;
		}
	}

	bool Contains(int val)
	{
		int index = HashFunction(val);

		if (hash[index] != NULL)
		{
			HashNode* current = hash[index];

			while (current != NULL)
			{
				if (current->val == val)
				{
					return true;
				}
				current = current->next;
			}
		}
		return false;
	}

	void DeleteElement(int val)
	{
		if (Contains(val) == true)
		{
			int index = HashFunction(val);
			HashNode* currentNode = hash[index];
			HashNode* prev = nullptr;
			while (currentNode != NULL)
			{
				if (currentNode->val == val)
				{
					break;
				}
				prev = currentNode;
				currentNode = currentNode->next;
			}
			if (prev == nullptr)
			{
				prev = hash[index]->next;
				delete hash[index];
				hash[index] = prev;
			}
			else
			{
				prev->next = currentNode->next;
				delete currentNode;
			}
			numberOfElements--;
		}
	}

	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			if (hash[i] != NULL)
			{
				HashNode* node = hash[i];
				if (node->next != NULL)
				{
					while (node != NULL)
					{
						if (node->next != NULL)
						{
							std::cout << node->val << "-->";
						}
						else
						{
							std::cout << node->val;
						}
						node = node->next;
					}
					std::cout << std::endl;
				}
				else
				{
					std::cout << node->val << std::endl;
				}
			}
		}
	}

	int NumberOfElements() { return numberOfElements; }
	int GetSize() { return size; }

	~Hash()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] hash[i];
		}
		delete[] hash;
	}

private:

	int HashFunction(int val)
	{
		int hash = val % size;
		if (hash < 0)
		{
			hash = hash * (-1); // for negative numbers
		}
		return hash;
	}

	int size;
	int numberOfElements;
	HashNode** hash;
};

int main()
{
	int n;
	std::cin >> n;

	Hash hash(n);
	int num;

	for (int i = 0; i < n; i++)
	{
		std::cin >> num;
		hash.Insert(num);
	}
	std::cout << std::endl;

	hash.Print();
	std::cout << std::endl;

	int elem;
	std::cout << "Enter the element that you want to delete: ";
	std::cin >> elem;

	hash.DeleteElement(elem);
	std::cout << std::endl;

	hash.Print();

	return 0;
}