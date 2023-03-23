#include <iostream>
#include <limits.h>
using namespace std;
int R[500], C[500], dp[500][500];

int solve(int left, int right)
{
    if (dp[left][right] > 0)
        return dp[left][right];
    if (right <= left)
        return 0;
    int mini = INT_MAX;
    for (int k = left; k < right; k++)
    {
        mini = min(mini, solve(left, k) + solve(k + 1, right) + R[left] * C[k] * C[right]);
    }
    return dp[left][right] = mini;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", R + i, C + i);
    }
    printf("%d\n", solve(0, N - 1));
}