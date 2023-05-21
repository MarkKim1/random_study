#include <iostream>
#include <vector>
using namespace std;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<vector<int>> map;
vector<vector<int>> visited;
int N, M, r, c, dir;

void input()
{
    cin >> N >> M;
    cin >> r >> c >> dir;
    map.resize(N, vector<int>(M, 0));
    visited.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
}

void dfs(int r, int c, int dir, int sum)
{
    for (int i = 0; i < 4; i++)
    {
        int next_dir = (dir + 3 - i) % 4;
        int nr = r + dx[next_dir];
        int nc = c + dy[next_dir];
        if (min(nr, nc) < 0 || nr >= N || nc >= M || map[nr][nc] == 1)
        {
            continue;
        }
        if (visited[nr][nc] == 0 and map[nr][nc] == 0)
        {
            visited[nr][nc] = 1;
            dfs(nr, nc, next_dir, sum + 1);
        }
    }
    int back_dir = dir + 2 < 4 ? dir + 2 : dir - 2;
    int back_r = r + dx[back_dir];
    int back_y = c + dy[back_dir];
    if (min(back_r, back_y) >= 0 and back_r < N and back_y < M)
    {
        if (map[back_r][back_y] == 0)
        {
            dfs(back_r, back_y, dir, sum);
        }
        else
        {
            cout << sum << "\n";
            exit(0);
        }
    }
}

int main()
{
    input();
    visited[r][c] = 1;
    dfs(r, c, dir, 1);
    return 0;
}