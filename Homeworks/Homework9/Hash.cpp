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
		currentSize = 0;
		hash = new HashNode*[size];
		for (int i = 0; i < size; i++)
		{
			hash[i] = NULL;
		}
	}

	void Insert(int val)
	{
		int index = (val % size);
		if (index < 0)
		{
			index = index * (-1);
		}
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
			currentSize++;
		}
	}

	bool Contains(int val)
	{
		int index = (val % size);
		if (index < 0)
		{
			index = index * (-1);
		}
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

	int GetCurrentSize() { return currentSize; }

	~Hash() 
	{
		for(int i = 0; i < currentSize; i++)
		{
			delete hash[i];
		}
		delete hash;
	}

private:
	int size;
	int currentSize;
	HashNode** hash;
};

int main()
{
	int n;
	std::cin >> n;

	Hash hash(n);
	long long num;

	for (int i = 0; i < n; i++)
	{
		std::cin >> num;
		hash.Insert(num);
	}
	std::cout << hash.GetCurrentSize();

	system("pause");
	return 0;
}