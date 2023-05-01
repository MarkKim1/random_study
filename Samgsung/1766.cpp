#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int N, T;

int main()
{
    cin >> N >> T;
    vector<int> Count(N + 1);
    unordered_map<int, vector<int>> node;
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < T; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        Count[b]++;
    }
    for (int i = 1; i <= N; i++)
    {
        if (Count[i] == 0)
        {
            pq.push(i);
        }
    }
    while (!pq.empty())
    {
        int curr_node = pq.top();
        result.push_back(curr_node);
        pq.pop();
        for (auto each : node[curr_node])
        {
            Count[each]--;
            if (Count[each] == 0)
            {
                pq.push(each);
            }
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
}