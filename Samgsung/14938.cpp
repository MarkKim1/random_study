#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
vector<int> item;
unordered_map<int, vector<pair<int, int>>> map;
int n, m, r;
const int MAX = 987654321;
int solve(int source)
{
    vector<int> temp(n + 1, MAX);
    temp[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int curr_distance = curr.first;
        int curr_node = curr.second;
        if (temp[curr_node] < curr_distance)
        {
            continue;
        }
        for (auto next_nodes : map[curr_node])
        {
            int next = next_nodes.first;
            int distance = next_nodes.second;
            int total = distance + curr_distance;
            if (temp[next] > total)
            {
                temp[next] = total;
                pq.push({total, next});
            }
        }
    }
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        if (temp[i] <= m)
        {
            result += item[i];
        }
    }
    return result;
}

int main()
{

    // n = 지역의 개수 m = 수색범위 r = 길의 개수
    cin >> n >> m >> r;
    item.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> item[i];
    }
    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({b, c});
        map[b].push_back({a, c});
    }
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result = max(result, solve(i));
    }
    cout << result << "\n";
}