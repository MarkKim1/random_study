#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

vector<pair<int, int>> graph[2001];
int stoAll[2001];
int htoAll[2001];
int gtoAll[2001];
int endp[101];

void dijkstra(int start, int dist[])
{
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int curr_node = curr.second;
        int curr_dist = curr.first;
        if (dist[curr_node] < curr_dist)
        {
            continue;
        }
        for (int i = 0; i < graph[curr_node].size(); i++)
        {
            int next_node = graph[curr_node][i].first;
            int dist_to_next_node = graph[curr_node][i].second;
            if (dist[next_node] > dist[curr_node] + dist_to_next_node)
            {
                dist[next_node] = dist[curr_node] + dist_to_next_node;
                pq.push({dist[next_node], next_node});
            }
        }
    }
}

void init()
{
    memset(stoAll, 127, sizeof(stoAll));
    memset(htoAll, 127, sizeof(htoAll));
    memset(gtoAll, 127, sizeof(gtoAll));
    memset(endp, 0, sizeof(endp));
    memset(graph, 0, sizeof(graph));
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        init();
        int INF = stoAll[0];
        int n, m, t, s, g, h, dist_GH;
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if ((a == g and b == h) || (a == h and b == g))
            {
                dist_GH = c;
            }
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        for (int i = 0; i < t; i++)
        {
            cin >> endp[i];
        }
        // find distance from s to all nodes;
        dijkstra(s, stoAll);
        dijkstra(g, gtoAll);
        dijkstra(h, htoAll);
        vector<int> ans;
        for (int i = 0; i < t; i++)
        {
            int final_node = endp[i];
            int temp;
            if (stoAll[g] < stoAll[h])
            {
                if (htoAll[final_node] == INF)
                {
                    continue;
                }
                temp = stoAll[g] + dist_GH + htoAll[final_node];
            }
            else
            {
                if (gtoAll[final_node] == INF)
                {
                    continue;
                }
                temp = stoAll[h] + dist_GH + gtoAll[final_node];
            }
            if (temp <= stoAll[final_node])
            {
                ans.push_back(final_node);
            }
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}