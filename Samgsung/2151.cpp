#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
vector<vector<char>> map;
int N;
int visited[51][51][4];
vector<pair<int, int>> door;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

struct INFO
{
    int x, y, dir;
};

void solve()
{
    queue<INFO> q;
    for (int i = 0; i < 4; i++)
    {
        q.push({door[0].first, door[0].second, i});
        visited[door[0].first][door[0].second][i] = 0;
    }

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int nx = curr.x + dx[curr.dir];
        int ny = curr.y + dy[curr.dir];
        if (min(nx, ny) >= 0 and nx < N and ny < N and map[nx][ny] != '*')
        {
            if (map[nx][ny] == '.' || map[nx][ny] == '#')
            {
                if (visited[nx][ny][curr.dir] > visited[curr.x][curr.y][curr.dir])
                {
                    visited[nx][ny][curr.dir] = visited[curr.x][curr.y][curr.dir];
                    q.push({nx, ny, curr.dir});
                }
            }
            else if (map[nx][ny] == '!')
            {
                if (visited[nx][ny][curr.dir] > visited[curr.x][curr.y][curr.dir])
                {
                    visited[nx][ny][curr.dir] = visited[curr.x][curr.y][curr.dir];
                    q.push({nx, ny, curr.dir});
                }
                for (int i = 1; i <= 3; i += 2)
                {
                    if (visited[nx][ny][(curr.dir + i) % 4] > visited[curr.x][curr.y][curr.dir] + 1)
                    {
                        visited[nx][ny][(curr.dir + i) % 4] = visited[curr.x][curr.y][curr.dir] + 1;
                        q.push({nx, ny, (curr.dir + i) % 4});
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> N;
    map.resize(N, vector<char>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '#')
            {
                door.push_back(make_pair(i, j));
            }
            for (int k = 0; k < 4; k++)
            {
                visited[i][j][k] = INT_MAX;
            }
        }
    }
    solve();
    int ans = INT_MAX;
    for (int i = 0; i < 4; i++)
    {
        ans = min(ans, visited[door[1].first][door[1].second][i]);
    }
    cout << ans << "\n";
}