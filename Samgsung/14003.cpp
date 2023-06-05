#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> vec(T);
    vector<int> count(T);
    unordered_map<int, priority_queue<int>> map;
    for (int i = 0; i < T; i++)
    {
        cin >> vec[i];
    }
    count[0] = 1;
    if (vec[1] > vec[0])
    {
        count[1] = 2;
    }
    else
    {
        count[1] = 1;
    }
    int ans = INT_MIN;
    for (int i = 2; i < T; i++)
    {
        int a = 0, b = 0;
        if (vec[i] > vec[i - 1])
        {
            a = count[i - 1] + 1;
        }
        if (vec[i] > vec[i - 2])
        {
            b = count[i - 2] + 1;
        }
        if (a == 0 and b == 0)
        {
            count[i] = 1;
        }
        else
        {
            count[i] = max(a, b);
        }
        ans = max(ans, count[i]);
        map[count[i]].push(vec[i]);
    }
    cout << ans << "\n";
    vector<int> ans_vec;
    while (ans)
    {
        ans_vec.push_back(map[ans].top());
        ans--;
    }
    for (int i = ans_vec.size() - 1; i >= 0; i--)
    {
        cout << ans_vec[i] << " ";
    }
    cout << "\n";
}