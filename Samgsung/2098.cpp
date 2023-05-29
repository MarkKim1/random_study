#include <iostream>
#include <cstring>

using namespace std;

#define INF 987654321;

int n, map[16][16];
int dp[16][1 << 16];

int dfs(int curr, int visit)
{
    if (visit == (1 << n) - 1)
    {
        if (map[curr][0] == 0)
        {
            return INF;
        }
        return map[curr][0];
    }
    if (dp[curr][visit] != -1)
    {
        return dp[curr][visit];
    }
    dp[curr][visit] = INF;
    for (int i = 0; i < n; i++)
    {
        if (map[curr][i] == 0)
        {
            continue;
        }
        if ((visit & (1 << i)) == (1 << i)) // 이미 방문 했다면 다음으로 넘어간다.
        {
            continue;
        }
        dp[curr][visit] = min(dp[curr][visit], map[curr][i] + dfs(i, visit | 1 << i));
    }
    return dp[curr][visit];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1) << "\n";
}