#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, a, b;
int shark_size = 2;
int result = 0;
vector<vector<int>> board;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
bool flag = false;
int fish_eat = 0;
void solve(int x, int y)
{
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x, y}}); // 상어의 시간, row, col
    vector<vector<bool>> visited(n, vector<bool>(n));
    visited[x][y] = true;
    int temp = 0;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int row = curr.second.first;
        int col = curr.second.second;
        int curr_time = curr.first;
        if (board[row][col] > 0 and board[row][col] < shark_size and temp == curr_time)
        {
            if (a > row || (a == row and b > col))
            {
                a = row;
                b = col;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int next_row = row + dx[i];
            int next_col = col + dy[i];
            if (min(next_row, next_col) >= 0 and next_row < n and next_col < n and !visited[next_row][next_col])
            {
                if (board[next_row][next_col] <= shark_size)
                {
                    if (board[next_row][next_col] > 0 and board[next_row][next_col] < shark_size and !flag)
                    {
                        a = next_row;
                        b = next_col;
                        temp = curr_time + 1;
                        result += temp;
                        flag = true;
                    }
                    else
                    {
                        q.push({curr_time + 1, {next_row, next_col}});
                        visited[next_row][next_col] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    board.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                a = i;
                b = j;
                board[i][j] = 0;
            }
        }
    }
    while (true)
    {
        solve(a, b);
        if (flag)
        {
            flag = false;
            fish_eat++;
            board[a][b] = 0;
            if (fish_eat == shark_size)
            {
                shark_size++;
                fish_eat = 0;
            }
        }
        else
        {
            break;
        }
    }
    cout << result << "\n";
}