#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, M;
    cin >> M >> N;
    vector<vector<int>> board(N, vector<int>(M));
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};
    queue<pair<int, int>> q;
    int tomato_count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                q.push(make_pair(i, j));
                board[i][j] = 2;
            }
            if (board[i][j] == 0)
            {
                tomato_count++;
            }
        }
    }
    int count = 0;
    int result = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nextX = curr.first + x[i];
                int nextY = curr.second + y[i];
                if (min(nextX, nextY) >= 0 and nextX < board.size() and nextY < board[0].size() and board[nextX][nextY] == 0)
                {
                    board[nextX][nextY] = 1;
                    q.push(make_pair(nextX, nextY));
                    count++;
                }
            }
        }
        result++;
    }
    // cout << tomato_count << endl;
    // cout << count << endl;
    if (tomato_count == count)
    {
        cout << result - 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}