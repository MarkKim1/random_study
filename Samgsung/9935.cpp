#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str, bomb, temp = "";
    cin >> str >> bomb;
    for (int i = 0; i < str.size(); i++)
    {
        temp += str[i];
        if (temp.back() == bomb.back())
        {
            bool is_bomb = true;
            if (temp.size() < bomb.size())
            {
                continue;
            }
            for (int j = 0; j < bomb.size(); j++)
            {
                if (temp[temp.size() - bomb.size() + j] != bomb[j])
                {
                    is_bomb = false;
                    break;
                }
            }
            if (is_bomb)
            {
                for (int j = 0; j < bomb.size(); j++)
                {
                    temp.pop_back();
                }
            }
        }
    }
    if (temp.empty())
    {
        cout << "FRULA"
             << "\n";
    }
    else
    {
        cout << temp << "\n";
    }
}