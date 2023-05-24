#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    vector<int> arr(n + 1);
    stack<int> S;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr[n] = -1;
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