#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    int T;
    cin >> T;
    unordered_map<int, vector<int>> map;
    vector<int> result(T + 1);
    vector<bool> visited(T + 1);
    queue<int> q;
    for (int i = 0; i < T - 1; i++)
    {
        int A, B;
        cin >> A >> B;
        map[A].push_back(B);
        map[B].push_back(A);
    }
    visited[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int curr = q.front();
            q.pop();
            for (auto each : map[curr])
            {
                if (visited[each] == 1)
                {
                    continue;
                }
                visited[each] = 1;
                result[each] = curr;
                q.push(each);
            }
        }
    }
    for (int i = 2; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}