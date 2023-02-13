#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>
using namespace std;
vector<vector<int>> vec;
vector<int> the;
unordered_map<int, vector<pair<int, int>>> map;
typedef pair<int, int> pii;
void solve(int i)
{
    vec[i][the[i]] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, the[i]});
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int curr_node = curr.second;
        int curr_distance = curr.first;
        if (curr_distance > vec[i][curr_node])
        {
            continue;
        }
        for (auto each : map[curr_node])
        {
            int next = each.first;
            int distance = each.second + curr_distance;
            if (distance < vec[i][next])
            {
                vec[i][next] = distance;
                pq.push({vec[i][next], next});
            }
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E;
    vec.resize(3, vector<int>(N + 1, 987654321));
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({b, c});
        map[b].push_back({a, c});
    }
    the.push_back(1);
    int a, b;
    cin >> a >> b;
    the.push_back(a);
    the.push_back(b);
    for (int i = 0; i < the.size(); i++)
    {
        solve(i);
    }
    int result = 987654321;
    result = min(result, vec[0][a] + vec[1][b] + vec[2][N]);
    result = min(result, vec[0][b] + vec[2][a] + vec[1][N]);
    if (vec[0][a] == 987654321 ||
        vec[0][b] == 987654321 ||
        vec[1][b] == 987654321 ||
        vec[2][a] == 987654321 ||
        vec[2][N] == 987654321 ||
        vec[1][N] == 987654321)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << result << "\n";
    }
}