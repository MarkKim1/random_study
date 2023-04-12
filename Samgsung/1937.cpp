#include <iostream>
#include <vector>
using namespace std;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int solve(vector<vector<int>> &board, vector<vector<int>> &memo, int i, int j)
{
    if (memo[i][j] != 0)
    {
        return memo[i][j];
    }
    for (int a = 0; a < 4; a++)
    {
        int ni = i + dx[a];
        int nj = j + dy[a];
        if (min(ni, nj) >= 0 and ni < board.size() and nj < board[0].size() and board[i][j] < board[ni][nj])
        {
            memo[i][j] = max(memo[i][j], solve(board, memo, ni, nj) + 1);
        }
    }
    return memo[i][j];
}

int main()
{
    int T;
    cin >> T;
    vector<vector<int>> board(T, vector<int>(T));
    vector<vector<int>> memo(T, vector<int>(T));
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            cin >> board[i][j];
        }
    }
    int result = 0;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            if (memo[i][j] == 0)
            {
                result = max(result, solve(board, memo, i, j));
            }
        }
    }
    cout << result + 1 << "\n";
}