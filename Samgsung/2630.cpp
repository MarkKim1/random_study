#include <iostream>
#include <vector>
using namespace std;
int W_result = 0;
int B_result = 0;
void solve(vector<vector<int>> &board, int x, int y, int T)
{
    int W = 0, B = 0;
    for (int i = x; i < x + T; i++)
    {
        for (int j = y; j < y + T; j++)
        {
            if (board[i][j] == 1)
            {
                B++;
            }
            else
            {
                W++;
            }
        }
    }
    if (B == T * T)
    {
        B_result++;
    }
    else if (W == T * T)
    {
        W_result++;
    }
    else
    {
        solve(board, x, y, T / 2);
        solve(board, x, y + T / 2, T / 2);
        solve(board, x + T / 2, y, T / 2);
        solve(board, x + T / 2, y + T / 2, T / 2);
    }
}

int main()
{
    int T;
    cin >> T;
    vector<vector<int>> board(T, vector<int>(T));

    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            cin >> board[i][j];
        }
    }
    solve(board, 0, 0, T);
    cout << W_result << endl;
    cout << B_result << endl;
}