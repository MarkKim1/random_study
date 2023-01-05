#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    vector<vector<char>> board(A, vector<char>(B));
    vector<vector<char>> original(A, vector<char>(B));
    int res = 0;
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < B; j++)
        {
            cin >> board[i][j];
            cin >> original[i][j];
        }
    }
    int result = INT_MAX;

    for (int i = 0; i < A - 8; i++)
    {
        for (int j = 0; j < B - 8; j++)
        {
            // 8 * 8 보드
            for (int k = i; k < i + 8; k++)
            {
                for (int n = j; n < j + 8; j++)
                {
                    if (board[k][n] == 'W')
                    {
                        if (k + 1 < A and board[k + 1][n] != 'B')
                        {
                            res++;
                            board[k + 1][n] = 'B';
                        }
                        if (n + 1 < B and board[k][n + 1] != 'B')
                        {
                            res++;
                            board[k][n + 1] = 'B';
                        }
                    }
                    else if (board[k][n] == 'B')
                    {
                        if (k + 1 < A and board[k + 1][n] != 'W')
                        {
                            res++;
                            board[k + 1][n] = 'W';
                        }
                        if (n + 1 < B and board[k][n + 1] != 'W')
                        {
                            res++;
                            board[k][n + 1] = 'W';
                        }
                    }
                }
            }
            result = min(result, res);
            res = 0;
            board = original;
        }
    }
    cout << result << endl;
}