#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            cout << s[i];
        }
        else
        {
            if (s[i] == '(')
            {
                stk.push(s[i]);
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                while (!stk.empty() and (stk.top() == '*' || stk.top() == '/'))
                {
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (stk.top() != '(')
                {
                    cout << stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else
            {
                while (!stk.empty() and stk.top() != '(')
                // while(!stk.empty()) 만 적었을경우 스택안에 있는 '(' 를 지우면서 s[i]가 ')'일때 마지막에 stk.pop()을 수행할수 없다 왜냐하면 이미 비어있는 스택이기 때문이다.
                {
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }
    }
    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
    cout << "\n";
}
