#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        int n;
        long long ans = 0;
        cin >> n;
        if (n == 0)
            break;
        vector<long long> arr(n + 1);
        arr[n] = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        stack<int> S;
        for (int i = 0; i <= n; i++)
        {
            while (!S.empty() and arr[i] < arr[S.top()])
            {
                long long height, weight;
                height = S.top();
                S.pop();
                if (S.empty())
                {
                    weight = i;
                }
                else
                {
                    weight = i - S.top() - 1;
                }
                ans = max(ans, arr[height] * weight);
            }
            S.push(i);
        }
        cout << ans << "\n";
    }
}