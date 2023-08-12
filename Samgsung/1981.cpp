#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;
int map[100][100];
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int curr_min = 0;
int curr_max = 201;
bool visited[100][100];
int T;
bool bfs(int diff)
{
    for (int i = curr_min; i <= curr_max; i++)
    {
        memset(visited, true, sizeof(visited));
        for (int j = 0; j < T; j++)
        {
            for (int k = 0; k < T; k++)
            {
                if (i <= map[j][k] and map[j][k] <= i + diff)
                {
                    visited[j][k] = false;
                }
            }
        }
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if (visited[curr.first][curr.second] == true)
                continue;
            visited[curr.first][curr.second] = true;
            if (curr.first == T - 1 and curr.second == T - 1)
            {
                return true;
            }
            for (int a = 0; a < 4; a++)
            {
                int nx = curr.first + dx[a];
                int ny = curr.second + dy[a];
                if (min(nx, ny) >= 0 and nx < T and ny < T)
                {
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

int main()
{

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            cin >> map[i][j];
            curr_min = min(curr_min, map[i][j]);
            curr_max = max(curr_max, map[i][j]);
        }
    }
    int left = 0;
    int right = curr_max - curr_min;
    int mid;
    while (left <= right)
    {
        mid = (right + left) / 2;
        if (bfs(mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << right + 1 << "\n";
}