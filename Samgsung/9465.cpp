#include <iostream>
#include <vector>
using namespace std;

int MAX(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int A;
        cin >> A;
        int dp[2][100001];
        int arr[2][100001];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < A; j++)
            {
                cin >> arr[i][j];
            }
        }
        dp[0][1] = arr[0][0];
        dp[1][1] = arr[1][0];
        for (int i = 2; i <= A; i++)
        {
            dp[0][i] = MAX(dp[1][i - 1], dp[1][i - 2]) + arr[0][i - 1];
            dp[1][i] = MAX(dp[0][i - 1], dp[0][i - 2]) + arr[1][i - 1];
        }
        cout << MAX(dp[0][A], dp[1][A]) << "\n";
    }
}