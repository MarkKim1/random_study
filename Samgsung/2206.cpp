#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct INFO
{
    int row, col, count;
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> board;
    vector<pair<int, int>> breakable;
    vector<int> x = {0, 1, 0, -1};
    vector<int> y = {1, 0, -1, 0};
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        board.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int count = 0;
            if (board[i][j] == '1')
            {
                if (i + 1 < N and board[i + 1][j] == '0')
                {
                    count++;
                }
                if (j + 1 < M and board[i][j + 1] == '0')
                {
                    count++;
                }
                if (j - 1 >= 0 and board[i][j - 1] == '0')
                {
                    count++;
                }
                if (i - 1 >= 0 and board[i - 1][j] == '0')
                {
                    count++;
                }
                if (count >= 2)
                {
                    breakable.push_back(make_pair(i, j));
                }
            }
        }
    }
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[0][0] = true;
    int result = -1;
    for (auto each : breakable)
    {
        board[each.first][each.second] = '0';
        queue<INFO> q;
        q.push({0, 0, 1});
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if (curr.row == N - 1 and curr.col == M - 1)
            {
                result = max(result, curr.count);
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int new_row = curr.row + x[i];
                int new_col = curr.col + y[i];
                if (min(new_row, new_col) >= 0 and new_row < N and new_col < M and !visited[new_row][new_col] and board[new_row][new_col] == '0')
                {
                    visited[new_row][new_col] = true;
                    q.push({new_row, new_col, curr.count + 1});
                }
            }
        }
        board[each.first][each.second] = '1';
        visited.assign(N, vector<bool>(M, false));
        visited[0][0] = true;
    }
    cout << result << endl;
}