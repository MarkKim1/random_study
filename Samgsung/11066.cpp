#include <iostream>
#include <cstring>
using namespace std;
int dp[501][501];
int sum[501], cost[501];

int solve(int left, int right)
{
    if (dp[left][right] != 0x3f3f3f3f)
    {
        return dp[left][right];
    }
    if (left == right)
    {
        return dp[left][right] = 0;
    }
    if (left + 1 == right)
    {
        return dp[left][right] = cost[left] + cost[right];
    }
    for (int mid = left; mid < right; mid++)
    {
        int curr1 = solve(left, mid);
        int curr2 = solve(mid + 1, right);
        dp[left][right] = min(dp[left][right], curr1 + curr2);
    }
    return dp[left][right] += sum[right] - sum[left - 1];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        memset(cost, 0, sizeof(cost));
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= N; i++)
        {
            cin >> cost[i];
            sum[i] = sum[i - 1] + cost[i];
        }
        cout << solve(1, N) << "\n";
    }
}