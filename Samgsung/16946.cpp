#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <limits.h>
using namespace std;
int N, M;
int map_index[1001][1001];
vector<vector<int>> visited;
vector<vector<int>> ans;
vector<vector<char>> map;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
vector<int> zero_nums;
int Cnt = 0;

void BFS(int i, int j)
{
    queue<pair<int, int>> q;

    visited[i][j] = 1;
    map_index[i][j] = Cnt;
    q.push(make_pair(i, j));
    int count = 1;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if (min(nx, ny) >= 0 and nx < N and ny < M and map[nx][ny] == '0' and visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                map_index[nx][ny] = Cnt;
                count++;
                q.push((make_pair(nx, ny)));
            }
        }
    }
    zero_nums.push_back(count);
}

void solve()
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == '0' and visited[i][j] == 0)
            {
                BFS(i, j);
                Cnt++;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == '1')
            {
                unordered_set<int> check;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (min(nx, ny) >= 0 and nx < N and ny < M and map[nx][ny] != '1')
                    {
                        if (check.find(map_index[nx][ny]) == check.end())
                        {
                            check.insert(map_index[nx][ny]);
                            ans[i][j] = ans[i][j] + zero_nums[map_index[nx][ny]];
                        }
                    }
                }
                ans[i][j] = ans[i][j] + 1;
                ans[i][j] = ans[i][j] % 10;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    visited.resize(N, vector<int>(M, 0));
    ans.resize(N, vector<int>(M));
    map.resize(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
    // memset(map_index, 0, sizeof(map_index));
    solve();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}