#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(3));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> board[i][j];
        }
    }
    int ans = 1000 * 1000 + 1;
    for (int i = 0; i < 3; i++)
    {
        int dp[1001][3];
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                dp[0][j] = board[0][j];
            else
                dp[0][j] = 1000 * 1000 + 1;
        }
        for (int k = 1; k < N; k++)
        {
            dp[k][0] = min(dp[k - 1][1], dp[k - 1][2]) + board[k][0];
            dp[k][1] = min(dp[k - 1][0], dp[k - 1][2]) + board[k][1];
            dp[k][2] = min(dp[k - 1][0], dp[k - 1][1]) + board[k][2];
        }
        for (int l = 0; l < 3; l++)
        {
            if (l == i)
                continue;
            ans = min(ans, dp[N - 1][l]);
        }
    }
    cout << ans << "\n";
}