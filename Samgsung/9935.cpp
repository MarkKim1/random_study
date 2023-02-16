#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str, bomb, result = "", temp = "";
    cin >> str >> bomb;
    int str_index = 0;
    int bomb_index = 0;
    stack<char> stk;
    while (str_index < str.size())
    {
        result += str[str_index];
        if (str[str_index] == bomb[0])
        {
            result.pop_back();
            while (str[str_index] == bomb[bomb_index])
            {
                result.push_back(str[str_index]);
                temp.push_back(str[str_index]);
                str_index++;
                bomb_index++;
            }
            if (temp == bomb)
            {
                break;
            }
            else
            {
                temp = "";
                bomb_index = 0;
            }
        }
        else
        {
            str_index++;
        }
    }
    for (int i = 0; i < bomb.size(); i++)
    {
        result.pop_back();
    }
    if (result.empty())
    {
        cout << "FRULA"
             << "\n";
    }
    else
    {
        cout << result << "\n";
    }
}