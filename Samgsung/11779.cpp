#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>
using namespace std;
unordered_map<int, vector<pair<int, int>>> graph;
int start, finish, n, m;

struct INFO
{
    int distance;
    vector<int> station;
};
vector<INFO> vec;
void solve()
{
    vec[start].distance = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int curr_distance = curr.first;
        int curr_node = curr.second;
        if (vec[curr_node].distance < curr_distance)
        {
            continue;
        }
        for (auto next_nodes : graph[curr_node])
        {
            int next_node = next_nodes.first;
            int distance_to_next_node = next_nodes.second;
            if (vec[next_node].distance > distance_to_next_node + curr_distance)
            {
                vec[next_node].distance = distance_to_next_node + curr_distance;
                vec[next_node].station = vec[curr_node].station;
                vec[next_node].station.push_back(next_node);
                pq.push({vec[next_node].distance, next_node});
            }
        }
    }
}

int main()
{

    // n = 도시의 개수 m = 버스의 개수
    cin >> n >> m;
    vec.resize(n + 1, {INT_MAX, vector<int>()});
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    cin >> start >> finish;
    solve();
    cout << vec[finish].distance << "\n";
    cout << vec[finish].station.size() + 1 << "\n";
    cout << start << " ";
    for (int i = 0; i < vec[finish].station.size(); i++)
    {
        cout << vec[finish].station[i] << " ";
    }
}