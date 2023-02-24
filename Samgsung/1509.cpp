// https://www.acmicpc.net/problem/1509
// 팰린드롬 분할 성공
#include <iostream>
#include <string>
#include <limits>
using namespace std;
bool palindrome[2501][2501];
int dp[2501];
int main()
{
    string str;
    cin >> str;
    int n = str.size();
    str = " " + str;

    for (int i = 1; i <= n; i++)
    {
        palindrome[i][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        palindrome[i][i + 1] = (str[i] == str[i + 1]);
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j + i <= n; j++)
        {
            if (str[j] == str[i + j] and palindrome[j + 1][i + j - 1] == 1)
            {
                palindrome[j][i + j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1e9;
        for (int j = 1; j <= i; j++)
        {
            if (palindrome[j][i])
            {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    cout << dp[n] << "\n";
}