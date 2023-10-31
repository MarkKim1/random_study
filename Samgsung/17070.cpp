#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int board[20][20];
    for (int i = 0; i < N; i++)
    {
        cout << "SEDFSF" << endl;
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 1}});
    int result = 0;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int type = curr.first;
        int row = curr.second.first;
        int col = curr.second.second;
        if (row == N - 1 and col == N - 1 and board[row][col] == 0)
        {
            result++;
            continue;
        }
        if (type == 0 || type == 2)
        {
            if (col + 1 < N and board[row][col + 1] == 0)
            {
                q.push({0, {row, col + 1}});
            }
        }
        if (type == 1 || type == 2)
        {
            if (row + 1 < N and board[row + 1][col] == 0)
            {
                q.push({1, {row + 1, col}});
            }
        }
        if (col + 1 < N and row + 1 < N)
        {
            if (board[row + 1][col + 1] == 0 and board[row + 1][col] == 0 and board[row][col + 1] == 0)
            {
                q.push({2, {row + 1, col + 1}});
            }
        }
    }
    cout << result << "\n";
}