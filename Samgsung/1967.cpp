#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int start = 1;
int result = INT_MIN;

void DFS(int curr_node, int curr_sum, vector<vector<pair<int, int>>> &vec, vector<bool> &visited)
{
    if (visited[curr_node] == true)
    {
        return;
    }
    if (result < curr_sum)
    {
        start = curr_node;
        result = curr_sum;
    }
    visited[curr_node] = true;
    for (auto each : vec[curr_node])
    {
        DFS(each.first, curr_sum + each.second, vec, visited);
    }
}

int main()
{
    int T;
    cin >> T;
    vector<vector<pair<int, int>>> vec(T + 1);
    vector<bool> visited(T + 1, false);
    for (int i = 0; i < T - 1; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        vec[from].push_back({to, weight});
        vec[to].push_back({from, weight});
    }
    DFS(1, 0, vec, visited);
    visited.assign(T + 1, false);
    DFS(start, 0, vec, visited);
    cout << result << "\n";
}