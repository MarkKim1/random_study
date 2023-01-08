#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int T;
    cin >> T;
    stack<int> stk;
    for (int i = 0; i < T; i++)
    {
        string S;
        int A;
        cin >> S;
        if (S == "push")
        {
            cin >> A;
            stk.push(A);
        }
        else if (S == "pop")
        {
            if (!stk.empty())
            {
                int temp = stk.top();
                stk.pop();
                cout << temp << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (S == "size")
        {
            cout << stk.size() << endl;
        }
        else if (S == "empty")
        {
            if (stk.empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (S == "top")
        {
            if (!stk.empty())
            {
                cout << stk.top() << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}