#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> vec;
    for (int i = 0; i < T; i++)
    {
        string S;
        cin >> S;
        if (S == "push")
        {
            int A;
            cin >> A;
            vec.push_back(A);
        }
        else if (S == "front")
        {
            if (vec.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << vec.front() << endl;
            }
        }
        else if (S == "pop")
        {
            if (vec.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                int curr = vec.front();
                vector<int> temp;
                for (int i = 1; i < vec.size(); i++)
                {
                    temp.push_back(vec[i]);
                }
                vec = temp;
                cout << curr << endl;
            }
        }
        else if (S == "size")
        {
            cout << vec.size() << endl;
        }
        else if (S == "empty")
        {
            if (vec.empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (S == "back")
        {
            if (vec.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << vec.back() << endl;
            }
        }
    }
}