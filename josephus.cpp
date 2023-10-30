#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int members;
    int permutation;
    queue<int> que;
    cin >> members;
    cin >> permutation;
    for (int i = 1; i <= members; i++)
    {
        que.push(i);
    }
    cout << "<";
    while (que.size())
    {
        if (que.size() == 1)
        {
            cout << que.front() << ">";
            que.pop();
            break;
        }
        for (int i = 1; i < permutation; i++)
        {
            que.push(que.front());
            que.pop();
        }
        cout << que.front() << ", ";
        que.pop();
    }
    cout << endl;
    return 0;
}