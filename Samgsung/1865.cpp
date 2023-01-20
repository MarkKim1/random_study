#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct INFO
{
    int S, E, T;
};

bool solve(int N, vector<INFO> graph)
{
    vector<int> dist(N + 1);
    dist[1] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            int s = graph[j].S;
            int e = graph[j].E;
            int t = graph[j].T;
            if (dist[e] > dist[s] + t)
            {
                dist[e] = dist[s] + t;
            }
        }
    }
    for (int j = 0; j < graph.size(); j++)
    {
        int s = graph[j].S;
        int e = graph[j].E;
        int t = graph[j].T;
        if (dist[e] > dist[s] + t)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int TC;
    cin >> TC;
    while (TC--)
    {
        vector<INFO> graph;
        int N, M, W;
        cin >> N >> M >> W;
        int s, e, t;
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
        if (solve(N, graph))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
