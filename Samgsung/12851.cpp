#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
const int MAX = 100001;

int main()
{
    int n, k;
    cin >> n >> k;
    int result = INT_MAX;
    int count = 0;
    vector<bool> visited(MAX, false);
    queue<pair<int, int>> q;
    q.push({n, 0});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int curr_node = curr.first;
        int curr_distance = curr.second;
        visited[curr_node] = true;
        if (result < curr_distance)
            break;
        if (curr_node == k)
        {
            result = curr_distance;
            count++;
            continue;
        }
        if (curr_node + 1 < MAX and !visited[curr_node + 1])
        {
            q.push({curr_node + 1, curr_distance + 1});
        }
        if (curr_node - 1 >= 0 and !visited[curr_node - 1])
        {
            q.push({curr_node - 1, curr_distance + 1});
        }
        if (curr_node * 2 < MAX and !visited[curr_node * 2])
        {
            q.push({curr_node * 2, curr_distance + 1});
        }
    }
    cout << result << "\n";
    cout << count << "\n";
}