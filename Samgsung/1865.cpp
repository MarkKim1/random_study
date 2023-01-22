#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct INFO
{
    int S, E, T;
};

bool solve(vector<INFO> &graph, int N, vector<int> &dist)
{
    dist[1] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int i = 0; i < graph.size(); i++)
        {
            int s = graph[i].S;
            int e = graph[i].E;
            int t = graph[i].T;
            if (dist[s] != INT_MAX and dist[e] > t + dist[s])
            {
                dist[e] = t + dist[s];
            }
        }
    }
    for (int i = 0; i < graph.size(); i++)
    {
        int s = graph[i].S;
        int e = graph[i].E;
        int t = graph[i].T;
        if (dist[s] != INT_MAX and dist[e] > t + dist[s])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int TC;
    cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        int N, M, W;
        cin >> N >> M >> W;
        vector<INFO> graph;
        vector<int> dist(N + 1);
        for (int i = 0; i < M; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            graph.push_back({s, e, t});
            graph.push_back({e, s, t});
        }
        for (int i = 0; i < W; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            graph.push_back({s, e, -t});
        }
        if (solve(graph, N, dist))
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}