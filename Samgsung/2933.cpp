#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
int R, C, N;
vector<vector<char>> map;
vector<int> order;
vector<vector<int>> visited;
queue<pair<int, int>> q;
vector<pair<int, int>> in_the_air;

void drop()
{
    int drop_location = INT_MAX;
    for (int i = 0; i < in_the_air.size(); i++)
    {
        int x = in_the_air[i].first;
        int y = in_the_air[i].second;
        int count = 0;
        while (x + 1 < R and visited[x + 1][y] != 1)
        {
            x++;
            count++;
        }
        drop_location = min(drop_location, count);
    }
    for (int i = in_the_air.size() - 1; i >= 0; i--)
    {
        int x = in_the_air[i].first;
        int y = in_the_air[i].second;
        map[x][y] = '.';
        map[x + drop_location][y] = 'x';
    }
}

void find_in_the_air()
{
    for (int a = 0; a < R; a++)
    {
        for (int b = 0; b < C; b++)
        {
            if (visited[a][b] == 0 and map[a][b] == 'x')
            {
                in_the_air.push_back(make_pair(a, b));
            }
        }
    }
}

void make_bfs()
{

    for (int b = 0; b < C; b++)
    {
        if (map[R - 1][b] == 'x')
        {
            q.push(make_pair(R - 1, b));
        }
    }
}

void reconstruct(int spear, int dir)
{
    if (dir % 2 == 0)
    {
        for (int j = C - 1; j >= 0; j--)
        {
            if (map[R - spear][j] == 'x')
            {
                map[R - spear][j] = '.';
                return;
            }
        }
    }
    else
    {
        for (int j = 0; j < C; j++)
        {
            if (map[R - spear][j] == 'x')
            {
                map[R - spear][j] = '.';
                return;
            }
        }
    }
}

void bfs()
{
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    while (!q.empty())
    {
        auto curr = q.front();

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if (min(nx, ny) >= 0 and nx < R and ny < C and map[nx][ny] == 'x' and visited[nx][ny] != 1)
            {
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void solve()
{
    int dir = 0;
    for (int i = 0; i < order.size(); i++)
    {
        int spear = order[i];
        dir++;
        reconstruct(spear, dir);
        make_bfs();
        bfs();
        find_in_the_air();
        drop();
        in_the_air.clear();
        visited.assign(R, vector<int>(C, 0));
    }
}

int main()
{
    cin >> R >> C;
    map.resize(R, vector<char>(C));
    visited.resize(R, vector<int>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }
    cin >> N;
    order.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> order[i];
    }
    solve();
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << map[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}