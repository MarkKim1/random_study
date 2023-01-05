#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string S;
    vector<string> vec;
    while (cin >> S)
    {
        if (S == "0")
        {
            break;
        }
        int left = 0;
        int right = S.size() - 1;
        bool a = true;
        while (left < right)
        {
            if (S[left++] != S[right--])
            {
                vec.push_back("no");
                a = false;
                break;
            }
        }
        if (a == true)
        {
            vec.push_back("yes");
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << endl;
    }
    return 0;
}