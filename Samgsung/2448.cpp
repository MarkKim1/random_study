#include <iostream>
using namespace std;
char board[3072][6144];

void solve(int x, int y, int n)
{
    if (n == 3)
    {
        board[x][y] = '*';
        board[x + 1][y - 1] = '*', board[x + 1][y + 1] = '*';
        for (int i = y - 2; i <= y + 2; i++)
        {
            board[x + 2][i] = '*';
        }
        return;
    }
    solve(x, y, n / 2);
    solve(x + (n / 2), y - (n / 2), n / 2);
    solve(x + (n / 2), y + (n / 2), n / 2);
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2; j++)
        {
            board[i][j] = ' ';
        }
    }
    solve(0, N - 1, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}