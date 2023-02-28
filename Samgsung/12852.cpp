#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> dp(N + 1, INT_MAX);
    dp[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i], dp[i / 2]);
        }
        if (i % 3 == 0)
        {
            dp[i] = min(dp[i], dp[i / 3]);
        }
        dp[i] = min(dp[i], dp[i - 1]);
        dp[i]++;
    }
    cout << dp[N] - 1 << "\n";
    while (N)
    {
        cout << N << " ";
        if (N % 3 == 0 and dp[N] == dp[N / 3] + 1)
        {
            N /= 3;
        }
        else if (N % 2 == 0 and dp[N] == dp[N / 2] + 1)
        {
            N /= 2;
        }
        else
        {
            N--;
        }
    }
    cout << "\n";
}