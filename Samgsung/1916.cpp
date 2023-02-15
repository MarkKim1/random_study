#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
vector<ll> nodes;
vector<vector<pii>> vec;
ll start, finish;

void solve()
{
    nodes[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        auto curr_node = curr.second;
        auto curr_distance = curr.first;
        if (nodes[curr_node] < curr_distance)
        {
            continue;
        }
        for (auto each : vec[curr_node])
        {
            auto next_node = each.first;
            auto distance = each.second;
            if (nodes[next_node] > distance + curr_distance)
            {
                nodes[next_node] = distance + curr_distance;
                pq.push(make_pair(nodes[next_node], next_node));
            }
        }
    }
}

int main()
{
    ll N, M;
    cin >> N >> M;
    nodes.resize(N + 1, 987654321);
    vec.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back(make_pair(b, c));
    }

    cin >> start >> finish;
    solve();
    cout << nodes[finish] << "\n";
}