#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX_N = 200000;
int T, n, a[MAX_N + 1], s[MAX_N + 1], dp[MAX_N + 1][MAX_N + 1];

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }

        for (int d = 1; d < n; d++)
        {
            for (int i = 1; i <= n - d; i++)
            {
                int j = i + d;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
                }
            }
        }

        cout << dp[1][n] << '\n';
    }

    return 0;
}