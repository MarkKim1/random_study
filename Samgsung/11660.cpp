#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, R;
    cin >> T >> R;
    int board[1026][1026];
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            int num;
            cin >> num;
            board[i + 1][j + 1] = board[i + 1][j] + board[i][j + 1] - board[i][j] + num;
        }
    }
    for (int i = 0; i < R; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << board[x2][y2] - board[x1 - 1][y2] - board[x2][y1 - 1] + board[x1 - 1][y1 - 1] << "\n";
    }
}