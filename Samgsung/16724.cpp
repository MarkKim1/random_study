#include <iostream>
#include <vector>
using namespace std;
char map[1001][1001];
int visited[1001][1001];
int N, M;
int ans = 0;
void solve(int i, int j)
{
    visited[i][j] = 1;
    int nx = i, ny = j;
    if (map[i][j] == 'D')
    {
        nx += 1;
    }
    if (map[i][j] == 'U')
    {
        nx -= 1;
    }
    if (map[i][j] == 'R')
    {
        ny += 1;
    }
    if (map[i][j] == 'L')
    {
        ny -= 1;
    }
    if (visited[nx][ny] == 1)
    {
        ans++;
    }
    if (visited[nx][ny] == 0)
    {
        solve(nx, ny);
    }
    visited[i][j] = 2;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == 0)
            {
                solve(i, j);
            }
        }
    }
    cout << ans << "\n";
}