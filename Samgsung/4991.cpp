#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
#include <limits.h>
using namespace std;
int R, C;
vector<vector<char>> map;
pair<int, int> robot;
int ans = INT_MAX;
int check[10];
struct INFO
{
    int r, c, count;
};

bool cmp(const INFO &a, const INFO &b)
{
    return a.count < b.count;
}

vector<INFO> dirty;

void init()
{
    map.resize(R, vector<char>(C));
    ans = INT_MAX;
    memset(check, 0, sizeof(check));
    dirty.clear();
}

int bfs(pair<int, int> robot, INFO dirty)
{
    // 거리를 계산한다

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    vector<vector<bool>> visited(R, vector<bool>(C));
    queue<INFO> q;
    q.push({robot.first, robot.second, 0});
    visited[robot.first][robot.second] = true;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if (curr.r == dirty.r and curr.c == dirty.c)
        {
            return curr.count;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = curr.r + dx[i];
            int ny = curr.c + dy[i];
            if (min(nx, ny) >= 0 and nx < R and ny < C and map[nx][ny] != 'x')
            {
                if (visited[nx][ny] == false)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, curr.count + 1});
                }
            }
        }
    }
    return INT_MAX;
}

void dfs(int index, pair<int, int> curr_location, int dist)
{
    if (dist > ans)
    {
        return;
    }
    if (index >= dirty.size())
    {
        ans = min(ans, dist);
        return;
    }
    for (int i = 0; i < dirty.size(); i++)
    {
        if (check[i])
            continue;
        check[i] = 1;
        int dist_from_curr_robot = bfs(curr_location, dirty[i]);
        pair<int, int> next = {dirty[i].r, dirty[i].c};
        dfs(index + 1, next, dist + dist_from_curr_robot);
        check[i] = 0;
    }
}

void solve()
{
    // 청소기에서 먼지까지의 거리를 먼저 계산한다.
    for (int i = 0; i < dirty.size(); i++)
    {
        dirty[i].count = bfs(robot, dirty[i]);
        if (dirty[i].count == INT_MAX)
        {
            ans = -1;
            return;
        }
    }
    sort(dirty.begin(), dirty.end(), cmp);
    dfs(0, robot, 0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> C >> R;
        if (!C and !R)
        {
            break;
        }
        init();
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'o')
                {
                    robot = make_pair(i, j);
                }
                else if (map[i][j] == '*')
                {
                    dirty.push_back({i, j, 0});
                }
            }
        }
        solve();
        if (ans == INT_MAX)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
}
