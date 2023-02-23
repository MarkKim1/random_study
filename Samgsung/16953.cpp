#include <iostream>
#include <queue>
using namespace std;
long long N, M;

int main()
{
    cin >> N >> M;
    queue<pair<long long, long long>> q;
    q.push({N, 0});
    bool flag = false;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if (curr.first == M)
        {
            cout << curr.second + 1 << "\n";
            flag = true;
            break;
        }
        if (curr.first * 2 <= M)
        {
            q.push({curr.first * 2, curr.second + 1});
        }
        if (curr.first * 10 + 1 <= M)
        {
            q.push({curr.first * 10 + 1, curr.second + 1});
        }
    }
    if (!flag)
    {
        cout << -1 << "\n";
    }
}