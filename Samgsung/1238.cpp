#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> graph[2][1001];
vector<vector<int>> dist;
int N, M, X;

void solve(int k)
{
    dist[k][X] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> minheap;
    minheap.push({0, X});
    while (!minheap.empty())
    {
        int curr_distance = minheap.top().first;
        int curr_node = minheap.top().second;
        minheap.pop();
        if (curr_distance > dist[k][curr_node])
        {
            continue;
        }
        for (int i = 0; i < graph[k][curr_node].size(); i++)
        {
            int next_node = graph[k][curr_node][i].first;
            int dist_to_next_node = graph[k][curr_node][i].second;
            if (dist[k][next_node] > curr_distance + dist_to_next_node)
            {
                dist[k][next_node] = curr_distance + dist_to_next_node;
                minheap.push({dist[k][next_node], next_node});
            }
        }
    }
}

int main()
{
    cin >> N >> M >> X;
    dist.resize(2, vector<int>(N + 1, INT_MAX));
    for (int i = 0; i < M; i++)
    {
        // from,to,distance
        int A, B, C;
        cin >> A >> B >> C;
        graph[0][A].push_back({B, C});
        graph[1][B].push_back({A, C});
    }
    solve(0);
    solve(1);
    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        result = max(result, dist[0][i] + dist[1][i]);
    }
    cout << result << "\n";
}