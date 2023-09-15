#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define endl "\n";
using namespace std;
const int MAX = 100;
int N, M, K;
char MAP[MAX][MAX];
long long DP[MAX][MAX][80];
string word;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int solve(int i, int j, int CNT)
{
    if (CNT >= word.length())
    {
        return 1;
    }
    if (DP[i][j][CNT] != -1)
    {
        return DP[i][j][CNT];
    }

    DP[i][j][CNT] = 0;
    for (int a = 0; a < 4; a++)
    {
        for (int k = 1; k <= K; k++)
        {
            int nx = i + (dx[a] * k);
            int ny = j + (dy[a] * k);
            if (min(nx, ny) >= 0 and nx < N and ny < M)
            {
                if (MAP[nx][ny] == word[CNT])
                {
                    DP[i][j][CNT] += solve(nx, ny, CNT + 1);
                }
            }
        }
    }
    return DP[i][j][CNT];
}

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }
    }
    cin >> word;
    long long ans = 0;
    memset(DP, -1, sizeof(DP));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (MAP[i][j] == word[0])
            {
                ans += solve(i, j, 1);
            }
        }
    }
    cout << ans << endl;
}