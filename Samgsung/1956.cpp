#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1, vector<int>(V + 1, 0));
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (graph[i][k] and graph[k][j])
                {
                    if (graph[i][j] != 0)
                    {
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                    else
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= V; i++)
    {
        if (graph[i][i] != 0)
        {
            ans = min(ans, graph[i][i]);
        }
    }
    if (ans == INT_MAX)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ans << "\n";
    }
}