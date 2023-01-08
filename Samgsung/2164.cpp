#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int T;
    cin >> T;
    queue<int> q;
    for (int i = 1; i <= T; i++)
    {
        q.push(i);
    }
    while (q.size() != 1)
    {
        q.pop();
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    cout << q.front() << endl;
}
