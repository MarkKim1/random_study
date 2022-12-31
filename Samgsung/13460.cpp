// 구슬 탈출 2
// https://www.acmicpc.net/problem/13460
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct INFO
{
    int r_row, r_col, b_row, b_col, count;
};

INFO start;
vector<vector<char>> board;
int bfs()
{
    queue<INFO> q;
    int result = -1;
    int visited[10][10][10][10];
    vector<int> x = {0, 1, 0, -1};
    vector<int> y = {1, 0, -1, 0};
    q.push(start);

    while (!q.empty())
    {
        INFO curr = q.front();
        q.pop();
        if (curr.count > 10)
        {
            break;
        }
        if (board[curr.r_row][curr.r_col] == 'O' and board[curr.b_row][curr.b_col] != 'O')
        {
            result = curr.count;
            break;
        }
        for (int dir = 0; dir < x.size(); dir++)
        {
            int newr_row = curr.r_row;
            int newr_col = curr.r_col;
            int newb_row = curr.b_row;
            int newb_col = curr.b_col;
            while (1)
            {
                if (board[newr_row][newr_col] != '#' and board[newr_row][newr_col] != 'O')
                {
                    newr_row += x[dir], newr_col += y[dir];
                }
                else if (board[newb_row][newb_col] != '#' and board[newb_row][newb_col] != 'O')
                {
                    newb_row += x[dir], newb_col += y[dir];
                }
                else
                {
                    if (board[newr_row][newr_col] == '#')
                    {
                        newr_row -= x[dir], newr_col -= y[dir];
                    }
                    if (board[newb_row][newb_col] == '#')
                    {
                        newb_row -= x[dir], newb_col -= y[dir];
                    }
                    break;
                }
            }
            if (board[newr_row][newr_col] == 'O' and board[newb_row][newb_col] == 'O')
            {
                continue;
            }
            if (newr_col == newb_col and newr_row == newb_row)
            {

                int R_dist = abs(newr_row - curr.r_row) + abs(newr_col - curr.r_col);
                int B_dist = abs(newb_col - curr.b_col) + abs(newb_row - curr.b_row);
                if (R_dist > B_dist)
                {
                    newr_row -= x[dir], newr_col -= y[dir];
                }
                else
                {
                    newb_row -= x[dir], newb_col -= y[dir];
                }
            }
            q.push({newr_row, newr_col, newb_row, newb_col, curr.count + 1});
        }
    }
    return result;
}

int main()
{
    int N, M;
    cin >> N >> M;
    board.assign(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                start.r_row = i;
                start.r_col = j;
            }
            if (board[i][j] == 'B')
            {
                start.b_row = i;
                start.b_col = j;
            }
        }
    }
    start.count = 0;
    int res = bfs();
    cout << res << endl;
}