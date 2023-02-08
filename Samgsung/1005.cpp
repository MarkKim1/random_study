#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int A, B;
        cin >> A >> B;
        vector<int> weight(A + 1);
        vector<int> result(A + 1);
        unordered_map<int, vector<int>> map;
        vector<int> depends(A + 1);
        queue<int> q;
        for (int i = 1; i <= A; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < B; i++)
        {
            int a, b;
            cin >> a >> b;
            map[a].push_back(b);
            depends[b]++;
        }
        int end;
        cin >> end;
        // need to find starting root;
        int start;
        for (int i = 1; i <= A; i++)
        {
            if (depends[i] == 0)
            {
                q.push(i);
            }
        }
        result = weight;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto next : map[curr])
            {
                result[next] = max(result[next], weight[next] + result[curr]);
                depends[next]--;
                if (depends[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        cout << result[end] << "\n";
    }
}