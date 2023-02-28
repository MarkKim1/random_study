#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000000;
int main()
{
    int a;
    cin >> a;
    vector<vector<int>> dp(101, vector<int>(10));
    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= a; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j + 1] % MOD;
            }
            if (j == 9)
            {
                dp[i][j] = dp[i - 1][j - 1] % MOD;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }
    long long sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        sum += dp[a][i] % MOD;
    }
    cout << sum % MOD << "\n";
}