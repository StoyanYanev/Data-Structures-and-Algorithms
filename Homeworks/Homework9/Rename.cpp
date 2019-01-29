#include<iostream>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>

int EqualSymbols(std::vector<std::string> saveNames, std::string currName)
{
    int count = 0;
    int maxCount = -1;
    for (int i = 0; i < saveNames.size(); i++)
    {
        for (int j = 0; j < currName.length(); j++)
        {
            if (j >= saveNames[i].length())
            {
                break;
            }
            if (saveNames[i][j] != currName[j])
            {
                break;
            }
            count++;
        }
        if (count > maxCount)
        {
            maxCount = count;
        }
        count = 0;
    }
    if (count > maxCount)
    {
        maxCount = count;
    }
    return maxCount;
}

int main()
{
    int n;
    std::string name;
    std::string newName = "";
    std::map<std::string, int> names;
    std::map<std::string, int> ::iterator it;
    std::vector<std::string> saveNames;
    int val = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> name;
        it = names.find(name);
        if (it != names.end())
        {
            val = it->second;
            std::cout << name << " " << val + 1 << std::endl;
            it->second = val + 1;
        }
        else
        {
            names.insert({ name, 1 });
            int index = EqualSymbols(saveNames, name);
            if (index != 0)
            {
                if (index == name.length())
                {
                    std::cout << name << std::endl;
                }
                else
                {
                    newName = name.substr(0, index+1);
                    std::cout << newName << std::endl;
                }
            }
            else
            {
                std::cout << name[0] << std::endl;
            }
            saveNames.push_back(name);
        }
    }

    return 0;
}