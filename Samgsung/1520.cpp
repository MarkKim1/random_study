#include <iostream>

using namespace std;
int memo[501][501];
int board[501][501];
int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int i, int j)
{
    if (i == N - 1 and j == M - 1)
    {
        return 1;
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    memo[i][j] = 0;
    for (int a = 0; a < 4; a++)
    {
        int nx = i + dx[a];
        int ny = j + dy[a];
        if (min(nx, ny) >= 0 and nx < N and ny < M)
        {
            if (board[nx][ny] < board[i][j])
            {
                memo[i][j] += dfs(nx, ny);
            }
        }
    }
    return memo[i][j];
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            memo[i][j] = -1;
        }
    }
    cout << dfs(0, 0) << "\n";
}