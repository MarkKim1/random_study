#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> time(N + 1);
    vector<int> Cnt(N + 1, 0);
    vector<int> Result(N + 1, 0);
    queue<int> q;
    unordered_map<int, vector<int>> node;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        time[i] = a;
        cin >> a;
        while (a != -1)
        {
            node[a].push_back(i);
            Cnt[i]++;
            cin >> a;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (Cnt[i] == 0)
        {
            Result[i] = time[i];
            q.push(i);
        }
    }
    while (q.size())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < node[curr].size(); i++)
        {
            int next_node = node[curr][i];
            Cnt[next_node]--;
            Result[next_node] = max(Result[next_node], time[next_node] + Result[curr]);
            if (Cnt[next_node] == 0)
            {
                q.push(next_node);
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout << Result[i] << "\n";
    }
}