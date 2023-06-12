#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> V;
    vector<int> arr;
    vector<int> count(1000001, 0);
    int T, cnt = 0;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
        auto it = lower_bound(V.begin(), V.end(), arr[i]) - V.begin();
        count[i] = it;
        if (it + V.begin() == V.end())
        {
            V.push_back(arr[i]);
            cnt++;
        }
        else
        {
            V[it] = arr[i];
        }
    }
    cout << cnt << "\n";
    vector<int> ans;
    for (int i = T - 1; i >= 0; i--)
    {
        if (cnt < 0)
            break;
        if (count[i] == cnt - 1)
        {
            ans.push_back(arr[i]);
            cnt--;
        }
    }
    while (!ans.empty())
    {
        cout << ans.back() << " ";
        ans.pop_back();
    }
}