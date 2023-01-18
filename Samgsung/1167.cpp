#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;
unordered_map<int, vector<pair<int, int>>> map;
int result = INT_MIN;
int maxnode;

void DFS(vector<bool> &visited, int curr, int sum)
{
    if (visited[curr])
    {
        return;
    }
    visited[curr] = true;
    for (auto each : map[curr])
    {
        int next_node = each.first;
        int distance = each.second;
        DFS(visited, next_node, sum + distance);
    }
    if (result < sum)
    {
        result = sum;
        maxnode = curr;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    vector<bool> visited(T + 1, false);
    int A, B, C;
    for (int i = 0; i < T; i++)
    {
        cin >> A;
        while (true)
        {
            cin >> B;
            if (B == -1)
            {
                break;
            }
            cin >> C;
            map[A].push_back(make_pair(B, C));
        }
    }
    DFS(visited, 1, 0);
    visited.assign(T + 1, false);
    DFS(visited, maxnode, 0);
    cout << result << "\n";
}