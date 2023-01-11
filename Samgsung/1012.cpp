#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &board, int i, int j)
{
    if (min(i, j) < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 1)
    {
        return;
    }
    board[i][j] = 0;
    DFS(board, i + 1, j);
    DFS(board, i - 1, j);
    DFS(board, i, j + 1);
    DFS(board, i, j - 1);
}

int main()
{
    int T;
    cin >> T;
    for (int Q = 0; Q < T; Q++)
    {
        int N, M, K;
        cin >> N >> M >> K;
        vector<vector<int>> board(N, vector<int>(M, 0));
        for (int j = 0; j < K; j++)
        {
            int A, B;
            cin >> A >> B;
            board[A][B] = 1;
        }
        int result = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == 1)
                {
                    result++;
                    DFS(board, i, j);
                }
            }
        }
        printf("%d\n", result);
    }
}