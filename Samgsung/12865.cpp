#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int weight[100], value[100];
int dp[101][100001];

int solve(int i, int w)
{
    if (dp[i][w] > 0)
        return dp[i][w];
    if (i == N)
        return 0;
    int n1 = 0;
    if (w + weight[i] <= K)
    {
        n1 = value[i] + solve(i + 1, w + weight[i]);
    }
    int n2 = solve(i + 1, w);
    return dp[i][w] = max(n1, n2);
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }
    cout << solve(0, 0);
}