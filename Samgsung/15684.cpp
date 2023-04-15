#include <iostream>
#include <limits.h>

using namespace std;
bool board[40][40];
int n, m, h, ans = INT_MAX, target_cnt;

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        int curr_line = i;
        for (int j = 1; j <= h; j++)
        {
            if (curr_line + 1 <= n and board[j][curr_line])
            {
                curr_line++;
            }
            else if (curr_line - 1 >= 1 and board[j][curr_line - 1])
            {
                curr_line--;
            }
        }
        if (curr_line != i)
        {
            return false;
        }
    }
    return true;
}

void DFS(int curr_row, int curr_col, int curr_cnt)
{
    if (curr_cnt == target_cnt)
    {
        if (check())
        {
            ans = curr_cnt;
        }
        return;
    }
    for (int i = curr_row, h_cnt = 1; i <= h; i++)
    {
        for (int j = h_cnt; j < n; j++)
        {
            if (board[i][j - 1] || board[i][j] || board[i][j + 1])
                continue;
            board[i][j] = 1;
            DFS(i, j, curr_cnt + 1);
            board[i][j] = 0;
        }
    }
}

int main()
{
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a][b] = true;
    }
    for (int i = 0; i <= 3; i++)
    {
        target_cnt = i;
        DFS(1, 1, 0);

        if (ans != INT_MAX)
        {
            cout << ans << "\n";
            break;
        }
    }
    if (ans == INT_MAX)
    {
        cout << -1 << "\n";
    }
}