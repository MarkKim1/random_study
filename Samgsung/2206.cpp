#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
int N, M;
int visited[1001][1001][2];
struct INFO
{
    int x;
    int y;
    int count;
    int broke;
};

bool isvalid(int next_x, int next_y)
{
    return min(next_x, next_y) >= 0 and next_x < N and next_y < M;
}

int main()
{

    cin >> N >> M;
    int board[1001][1001];
    vector<int> row = {0, 1, 0, -1};
    vector<int> col = {-1, 0, 1, 0};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &board[i][j]);
        }
    }
    queue<INFO> q;
    q.push({0, 0, 1, false});
    visited[0][0][0] = true;
    visited[0][0][1] = true;
    int result = INT_MAX;
    while (!q.empty())
    {
        INFO curr = q.front();
        q.pop();
        if (curr.x == N - 1 and curr.y == M - 1)
        {
            result = min(curr.count, result);
        }
        for (int i = 0; i < 4; i++)
        {
            int next_x = curr.x + row[i];
            int next_y = curr.y + col[i];

            if (isvalid(next_x, next_y))
            {
                if (board[next_x][next_y] == 1 and curr.broke == 0 and !visited[next_x][next_y][curr.broke + 1])
                {
                    visited[next_x][next_y][curr.broke + 1] = 1;
                    q.push({next_x, next_y, curr.count + 1, curr.broke + 1});
                }
                else if (board[next_x][next_y] == 0 and !visited[next_x][next_y][curr.broke])
                {
                    visited[next_x][next_y][curr.broke] = true;
                    q.push({next_x, next_y, curr.count + 1, curr.broke});
                }
            }
        }
    }
    result == INT_MAX ? cout << -1 << "\n" : cout << result << "\n";
}