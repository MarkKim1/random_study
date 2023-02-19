#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
vector<int> x{0, 1, 0, -1};
vector<int> y{1, 0, -1, 0};
int BFS(queue<pair<int, int>> q, vector<vector<int>> vec, int zero_count)
{
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int row = curr.first + x[i];
            int col = curr.second + y[i];
            if (min(row, col) >= 0 and row < vec.size() and col < vec[0].size())
            {
                if (vec[row][col] == 0)
                {
                    vec[row][col] = 2;
                    q.push({row, col});
                    zero_count--;
                }
            }
        }
    }
    return zero_count;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> vec(N, vector<int>(M));
    vector<pair<int, int>> zero;
    queue<pair<int, int>> q;
    int zero_count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> vec[i][j];
            if (vec[i][j] == 0)
            {
                zero_count++;
                zero.push_back({i, j});
            }
            if (vec[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }
    int result = INT_MIN;
    zero_count -= 3;
    for (int i = 0; i < zero.size(); i++)
    {
        for (int j = i + 1; j < zero.size(); j++)
        {
            for (int k = j + 1; k < zero.size(); k++)
            {
                vec[zero[i].first][zero[i].second] = 1;
                vec[zero[j].first][zero[j].second] = 1;
                vec[zero[k].first][zero[k].second] = 1;
                result = max(result, BFS(q, vec, zero_count));
                vec[zero[i].first][zero[i].second] = 0;
                vec[zero[j].first][zero[j].second] = 0;
                vec[zero[k].first][zero[k].second] = 0;
            }
        }
    }
    cout << result << "\n";
}