#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pi;
int main()
{
    int T, R;
    cin >> T >> R;
    unordered_map<int, vector<pi>> graph;
    queue<int> q;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> visited(T + 1, 0);
    for (int i = 0; i < R; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }
    for (auto each : graph[1])
    {
        int next_node = each.first;
        int weight_to_next_node = each.second;
        pq.push({weight_to_next_node, next_node});
    }
    visited[1] = 1;
    int result = 0;
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int next_node = curr.second;
        int weight_to_next_node = curr.first;
        if (visited[next_node])
            continue;
        visited[next_node] = 1;
        result += weight_to_next_node;
        for (auto neighbors : graph[next_node])
        {
            if (visited[neighbors.first])
                continue;
            pq.push({neighbors.second, neighbors.first});
        }
    }
    cout << result << "\n";
}