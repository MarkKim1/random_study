#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> vec(N + 1);
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        int curr = INT_MAX;
        for (int j = 0; j < a; j++)
        {
            if (curr == INT_MAX)
            {
                cin >> curr;
            }
            else
            {
                int now;
                cin >> now;
                map[curr].push_back(now);
                vec[now]++;
                curr = now;
            }
        }
    }
    queue<int> q;
    vector<int> result;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        result.push_back(curr);
        for (auto each : map[curr])
        {
            vec[each]--;
            if (vec[each] == 0)
            {
                q.push(each);
            }
        }
    }
    if (result.size() != N)
    {
        cout << 0 << "\n";
    }
    else
    {
        for (int a : result)
        {
            cout << a << "\n";
        }
    }
    return 0;
}