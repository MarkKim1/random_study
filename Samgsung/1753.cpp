#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int V, E;
int start;
int u, v, w;

void solve(vector<vector<pair<int, int>>> graph, vector<int> &dist)
{
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        for (int i = 0; i < graph[curr.second].size(); i++)
        {
            int next_node = graph[curr.second][i].first;
            int weight_from_start = graph[curr.second][i].second;
            if (dist[next_node] > curr.first + weight_from_start)
            {
                dist[next_node] = curr.first + weight_from_start;
                pq.push({dist[next_node], next_node});
            }
        }
    }
}

int main()
{
    cin >> V >> E;
    vector<vector<pair<int, int>>> graph(V + 1);
    vector<int> dist(V + 1, INT_MAX);
    cin >> start;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    solve(graph, dist);

    for (int i = 1; i < dist.size(); i++)
    {
        if (i == start)
        {
            cout << 0 << "\n";
        }
        else if (dist[i] == INT_MAX)
        {
            cout << "INF"
                 << "\n";
        }
        else
        {
            cout << dist[i] << "\n";
        }
    }
}
