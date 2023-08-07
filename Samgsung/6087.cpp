#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
vector<vector<char>> map;
vector<vector<int>> visited;
pair<int, int> s, f;
bool flag = false;
int R, C;

int solve()
{
    queue<pair<int, pair<int, int>>> q;
    q.push({s.first, {s.second, 1}});
    visited[s.first][s.second] = 1;

    while (!q.empty())
    {
        auto curr = q.front();
        int x = curr.first;
        int y = curr.second.first;
        int cnt = curr.second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while (min(nx, ny) >= 0 and nx < R and ny < C)
            {
                if (map[nx][ny] == '*')
                {
                    break;
                }
                if (visited[nx][ny] == -1)
                {
                    visited[nx][ny] = cnt;
                    q.push({nx, {ny, cnt + 1}});
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    return visited[f.first][f.second];
}

int main()
{
    cin >> C >> R;
    map.resize(R, vector<char>(C));
    visited.resize(R, vector<int>(C, -1));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'C')
            {
                if (!flag)
                {
                    s = {i, j};
                    flag = true;
                }
                else
                {
                    f = {i, j};
                }
            }
        }
    }
    cout << solve() - 1 << "\n";
}