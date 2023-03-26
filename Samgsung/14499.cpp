#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M, x, y, K;
    cin >> N >> M >> y >> x >> K;
    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<int> dice(7, 0);
    vector<int> temp(7, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        int dir;
        cin >> dir;
        if (dir == 1)
        {
            if (x + 1 < M)
            {
                x++;
                temp[1] = dice[1];
                temp[3] = dice[3];
                temp[6] = dice[6];
                temp[4] = dice[4];

                dice[1] = temp[4];
                dice[3] = temp[1];
                dice[6] = temp[3];
                dice[4] = temp[6];
                if (board[y][x] == 0)
                {
                    board[y][x] = dice[6];
                }
                else
                {
                    dice[6] = board[y][x];
                    board[y][x] = 0;
                }
                cout << dice[1] << "\n";
            }
        }
        else if (dir == 2)
        {
            if (x - 1 >= 0)
            {
                x--;
                temp[1] = dice[1];
                temp[4] = dice[4];
                temp[6] = dice[6];
                temp[3] = dice[3];

                dice[1] = temp[3];
                dice[4] = temp[1];
                dice[6] = temp[4];
                dice[3] = temp[6];
                if (board[y][x] == 0)
                {
                    board[y][x] = dice[6];
                }
                else
                {
                    dice[6] = board[y][x];
                    board[y][x] = 0;
                }
                cout << dice[1] << "\n";
            }
        }
        else if (dir == 3)
        {
            if (y - 1 >= 0)
            {
                y--;
                temp[1] = dice[1];
                temp[2] = dice[2];
                temp[6] = dice[6];
                temp[5] = dice[5];

                dice[1] = temp[5];
                dice[2] = temp[1];
                dice[6] = temp[2];
                dice[5] = temp[6];
                if (board[y][x] == 0)
                {
                    board[y][x] = dice[6];
                }
                else
                {
                    dice[6] = board[y][x];
                    board[y][x] = 0;
                }
                cout << dice[1] << "\n";
            }
        }
        else
        {
            if (y + 1 < N)
            {
                y++;
                temp[1] = dice[1];
                temp[5] = dice[5];
                temp[6] = dice[6];
                temp[2] = dice[2];

                dice[1] = temp[2];
                dice[5] = temp[1];
                dice[6] = temp[5];
                dice[2] = temp[6];
                if (board[y][x] == 0)
                {
                    board[y][x] = dice[6];
                }
                else
                {
                    dice[6] = board[y][x];
                    board[y][x] = 0;
                }
                cout << dice[1] << "\n";
            }
        }
    }
}