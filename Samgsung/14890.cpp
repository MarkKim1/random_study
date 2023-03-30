#include <iostream>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;
    int board[200][100];
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i + N][j] = board[j][i];
        }
    }
    // 가로--------------------------------------------------------------------------------
    for (int row = 0; row < N * 2; row++)
    {
        int same_num = 1;
        bool stop = false;
        for (int col = 0; col < N - 1; col++)
        {
            if (board[row][col] == board[row][col + 1])
            // 만약 같은 숫자가 나온다면
            {
                same_num++;
            }
            else if (board[row][col] + 1 == board[row][col + 1])
            // 만약 현재 숫자보다 1 큰 숫자가 나타난다면
            {
                if (same_num < L)
                {
                    stop = true;
                    break;
                }
                else
                {
                    same_num = 1;
                }
            }
            else if (board[row][col] == board[row][col + 1] + 1)
            // 만약 현재 숫자보다 1 작은 숫자가 나온다면
            {
                int cnt = 0;
                for (int k = 0; k < L; k++)
                {
                    if (col + 1 + k < N and board[row][col + 1] == board[row][col + 1 + k])
                    {
                        cnt++;
                    }
                }
                if (cnt < L)
                {
                    stop = true;
                    break;
                }
                else
                {
                    col += cnt - 1;
                    same_num = 0;
                }
            }
            else
            {
                stop = true;
                break;
            }
        }
        if (!stop)
        {
            // cout << row << " ";
            ans++;
        }
    }
    cout << ans << "\n";
}