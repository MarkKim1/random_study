#include <iostream>
#include <vector>
using namespace std;
int row[9][10];
int col[9][10];
int section[9][10];
int board[9][9];
vector<pair<int, int>> zero;
int cnt = 0;
bool solve(int N)
{
    if (N == cnt)
    {
        return true;
    }
    for (int i = 1; i <= 9; i++)
    {
        board[zero[N].first][zero[N].second] = i;
        if (row[zero[N].first][i] != i and
            col[zero[N].second][i] != i and
            section[(zero[N].first / 3) * 3 + (zero[N].second / 3)][i] != i)
        {
            row[zero[N].first][i] = i;
            col[zero[N].second][i] = i;
            section[(zero[N].first / 3) * 3 + (zero[N].second / 3)][i] = i;
            if (solve(N + 1))
            {
                return true;
            }
            row[zero[N].first][i] = 0;
            col[zero[N].second][i] = 0;
            section[(zero[N].first / 3) * 3 + (zero[N].second / 3)][i] = 0;
        }
    }
    board[zero[N].first][zero[N].second] = 0;
    return false;
}

int main()
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char a;
            cin >> a;
            board[i][j] = a - '0';
            if (board[i][j] == 0)
            {
                zero.push_back({i, j});
                cnt++;
            }
            else
            {
                row[i][board[i][j]] = board[i][j];
                col[j][board[i][j]] = board[i][j];
                section[(i / 3) * 3 + (j / 3)][board[i][j]] = board[i][j];
            }
        }
    }
    solve(0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}