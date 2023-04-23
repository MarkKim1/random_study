#include <iostream>
#include <queue>
#include <limits.h>

#define endl "\n"
#define MAX 200
using namespace std;

int W, H, K;
int map[MAX][MAX];
int Visit[MAX][MAX][31];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int hdx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int hdy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

void input()
{
    cin >> K;
    cin >> W >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> map[i][j];
        }
    }
}

void solve()
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    Visit[0][0][0] = 1;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int Cnt = q.front().second.first;
        int Ability = q.front().second.second;
        q.pop();
        if (x == H - 1 and y == W - 1)
        {
            cout << Cnt << endl;
            return;
        }
        if (Ability < K)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x + hdx[i];
                int ny = y + hdy[i];
                if (min(nx, ny) >= 0 and nx < H and ny < W)
                {
                    if (map[nx][ny] == 0 and Visit[nx][ny][Ability + 1] == 0)
                    {
                        Visit[nx][ny][Ability + 1] = 1;
                        q.push({{nx, ny}, {Cnt + 1, Ability + 1}});
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (min(nx, ny) >= 0 and nx < H and ny < W)
            {
                if (map[nx][ny] == 0 and Visit[nx][ny][Ability] == 0)
                {
                    Visit[nx][ny][Ability] = 1;
                    q.push({{nx, ny}, {Cnt + 1, Ability}});
                }
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}
