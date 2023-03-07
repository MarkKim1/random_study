#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> vec(N + 1);
    unordered_map<int, vector<int>> map;
    vector<int> result;
    queue<int> q;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        vec[b]++;
    }

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] == 0)
        {
            result.push_back(i);
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto each : map[curr])
        {
            vec[each]--;
            if (vec[each] == 0)
            {
                q.push(each);
                result.push_back(each);
            }
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
}