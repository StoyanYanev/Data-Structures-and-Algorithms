#include<iostream>
#include<set>
#include<string>

using namespace std;

int main()
{
	string word;
	set<string> uniqueWords;
	set<string> allWords;

	while (cin >> word)
	{
		if (allWords.find(word) == allWords.end())
		{
			allWords.insert(word);
			uniqueWords.insert(word);
		}
		else
		{
			if (uniqueWords.find(word) != uniqueWords.end())
			{
				uniqueWords.erase(uniqueWords.find(word));
			}
		}
	}

	set<string>::iterator it;
	for (it = uniqueWords.begin(); it != uniqueWords.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}