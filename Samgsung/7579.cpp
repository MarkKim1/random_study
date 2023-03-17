#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int bite[101], C[101], dp[101][10001];
int result = 0;
int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> bite[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> C[i];
        result += C[i];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= result; j++)
        {
            if (j - C[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - C[i]] + bite[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    for (int i = 0; i <= result; i++)
    {
        if (dp[N][i] >= M)
        {
            cout << i << "\n";
            break;
        }
    }
}