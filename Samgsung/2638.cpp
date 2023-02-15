#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> x = {-1, 0, 1, 0};
vector<int> y = {0, 1, 0, -1};
vector<vector<int>> board;
vector<vector<int>> temp;
queue<pair<int, int>> q;
int result = 0;
int N, M;
void mark_outside()
{

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int row = x[i] + curr.first;
            int col = y[i] + curr.second;
            if (min(row, col) >= 0 and row < N and col < M)
            {
                if (board[row][col] == 0)
                {
                    board[row][col] = 3;
                    temp[row][col] = 3;
                    q.push({row, col});
                }
            }
        }
    }
}

void solve()
{
    while (true)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                int count = 0;
                if (board[i][j] == 1)
                {
                    for (int a = 0; a < 4; a++)
                    {
                        int row = i + x[a];
                        int col = j + y[a];
                        if (min(row, col) >= 0 and row < N and col < M)
                        {
                            if (board[row][col] == 3)
                            {
                                count++;
                            }
                        }
                    }
                    if (count >= 2)
                    {
                        temp[i][j] = 3;
                        q.push({i, j});
                    }
                }
            }
        }
        board = temp;
        result++;
        if (q.empty())
        {
            break;
        }
        else
        {
            mark_outside();
        }
    }
}

int main()
{

    cin >> N >> M;
    board.resize(N, vector<int>(M));
    temp.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    q.push({0, 0});
    board[0][0] = 3;
    mark_outside();
    temp = board;
    solve();
    cout << result - 1 << "\n";
}