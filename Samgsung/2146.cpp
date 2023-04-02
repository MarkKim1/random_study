#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

void set_continent(vector<vector<int>> &board, int continent_number, int i, int j)
{
    int T = board.size();
    queue<pair<int, int>> q;
    q.push({i, j});
    vector<vector<int>> visited(T, vector<int>(T));
    visited[i][j] = 1;
    while (!q.empty())
    {
        auto curr = q.front();
        board[curr.first][curr.second] = continent_number;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newi = curr.first + dx[i];
            int newj = curr.second + dy[i];
            if (min(newi, newj) >= 0 and newi < board.size() and newj < board[0].size() and visited[newi][newj] == 0 and board[newi][newj] == 1)
            {
                q.push({newi, newj});
                visited[newi][newj] = 1;
                board[newi][newj] = continent_number;
            }
        }
    }
}

int get_distance(vector<vector<int>> &board, int curr_continent_number, vector<vector<int>> &visited_continent, int i, int j)
{
    int T = board.size();
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    vector<vector<int>> visited(T, vector<int>(T));
    int ans = INT_MAX;
    visited[i][j] = 1;
    visited_continent[i][j] = 1;
    q1.push({i, j});
    while (!q1.empty())
    {
        auto curr = q1.front();
        q1.pop();
        q2.push(curr);
        for (int i = 0; i < 4; i++)
        {
            int newi = curr.first + dx[i];
            int newj = curr.second + dy[i];
            if (min(newi, newj) >= 0 and newi < T and newj < T and visited[newi][newj] == 0 and board[newi][newj] == curr_continent_number)
            {
                visited[newi][newj] = 1;
                visited_continent[newi][newj] = 1;
                q1.push({newi, newj});
            }
        }
    }
    int distance = 0;
    while (!q2.empty())
    {
        int size = q2.size();
        for (int a = 0; a < size; a++)
        {
            auto curr = q2.front();
            int curr_i = curr.first;
            int curr_j = curr.second;
            q2.pop();
            for (int i = 0; i < 4; i++)
            {
                int new_i = curr_i + dx[i];
                int new_j = curr_j + dy[i];
                if (min(new_i, new_j) >= 0 and new_i < board.size() and new_j < board[0].size() and visited[new_i][new_j] == 0)
                {
                    if (board[new_i][new_j] == 0)
                    {
                        visited[new_i][new_j] = 1;
                        q2.push({new_i, new_j});
                    }
                    else
                    {
                        ans = min(ans, distance);
                    }
                }
            }
        }
        distance++;
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    vector<vector<int>> board(T, vector<int>(T, 0));
    vector<vector<int>> visited_continent(T, vector<int>(T));
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            cin >> board[i][j];
        }
    }
    int continent_number = -1;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            if (board[i][j] == 1)
            {
                set_continent(board, continent_number, i, j);
                continent_number--;
            }
        }
    }
    int result = INT_MAX;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            if (board[i][j] != 0 and visited_continent[i][j] == 0)
            {
                result = min(result, get_distance(board, board[i][j], visited_continent, i, j));
            }
        }
    }
    cout << result << "\n";
}