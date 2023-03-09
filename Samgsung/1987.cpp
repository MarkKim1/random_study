#include <iostream>
#include <vector>
using namespace std;
vector<int> alpha(26);
vector<vector<char>> board;
int N, M;
int result = 0;
int DFS(int i, int j, int cnt)
{
    if (min(i, j) < 0 || i >= N || j >= M || alpha[board[i][j] - 'A'])
    {
        return cnt;
    }
    alpha[board[i][j] - 'A'] = 1;
    result = max(result, DFS(i + 1, j, cnt + 1));
    result = max(result, DFS(i - 1, j, cnt + 1));
    result = max(result, DFS(i, j + 1, cnt + 1));
    result = max(result, DFS(i, j - 1, cnt + 1));
    alpha[board[i][j] - 'A'] = 0;
    return result;
}

int main()
{

    cin >> N >> M;

    board.resize(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    cout << DFS(0, 0, 0) << "\n";
}