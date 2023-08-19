#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;
int N, M;

struct INFO
{
    int FROM, TO, DIST;
};
vector<INFO> map;
vector<long long> dist(501, LLONG_MAX);

void solve()
{

    dist[1] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < map.size(); j++)
        {
            int FROM = map[j].FROM;
            int TO = map[j].TO;
            int DIST = map[j].DIST;
            if (dist[FROM] == LLONG_MAX)
            {
                continue;
            }
            if (dist[TO] > dist[FROM] + DIST)
            {
                dist[TO] = dist[FROM] + DIST;
            }
        }
    }
    for (int i = 0; i < map.size(); i++)
    {
        int FROM = map[i].FROM;
        int TO = map[i].TO;
        int DIST = map[i].DIST;
        if (dist[FROM] == LLONG_MAX)
        {
            continue;
        }
        if (dist[TO] > dist[FROM] + DIST)
        {
            cout << -1 << "\n";
            return;
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (dist[i] == LLONG_MAX)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << dist[i] << "\n";
        }
    }
}

int main()
{

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map.push_back({a, b, c});
    }
    solve();
}