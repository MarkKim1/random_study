#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
char board[8][8];

vector<int> dx = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int ans = 0;

void move()
{
    for (int i = 7; i >= 1; i--)
    {
        for (int j = 7; j >= 0; j--)
        {
            board[i][j] = board[i - 1][j];
        }
    }
    for (int i = 0; i < 7; i++)
    {
        board[0][i] = '.';
    }
}

void solve()
{
    queue<pair<int, int>> q;
    q.push({7, 0});
    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int a = 0; a < size; a++)
        {
            auto curr = q.front();
            int x = curr.first;
            int y = curr.second;
            q.pop();
            if (board[x][y] == '#')
                continue;
            if (time >= 8 || (x == 0 and y == 7))
            {
                ans = 1;
                return;
            }
            for (int i = 0; i < 9; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (min(nx, ny) >= 0 and nx < 8 and ny < 8 and board[nx][ny] != '#')
                {
                    if (nx >= 1 and board[nx - 1][ny] == '#')
                    {
                        continue;
                    }
                    q.push({nx, ny});
                }
            }
        }
        move();
        time++;
    }
}

int main()
{

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> board[i][j];
        }
    }
    solve();
    cout << ans << "\n";
}