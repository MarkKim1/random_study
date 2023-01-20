#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<vector<pair<int, int>>> map;
int V, E;
int root;
int main()
{
    cin >> V >> E;
    cin >> root;
    map.resize(V + 1);
    vector<int> visited(V + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        map[u].push_back(make_pair(v, w));
    }
    pq.push(make_pair(0, root));
    while (!pq.empty())
    {
        int curr = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        for (auto neighbors : map[curr])
        {
            int next_node = neighbors.first;
            int weight_to_next = neighbors.second;
            if (visited[next_node] > weight + weight_to_next)
            {
                visited[next_node] = weight + weight_to_next;
                pq.push(make_pair(visited[next_node], next_node));
            }
        }
    }
    visited[root] = 0;
    for (int i = 1; i < visited.size(); i++)
    {
        if (visited[i] == INT_MAX)
        {
            cout << "INF"
                 << "\n";
        }
        else
        {
            cout << visited[i] << "\n";
        }
    }
}