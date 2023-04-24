#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
int N, M;
vector<pair<int, int>> virus_locations;
vector<pair<int, int>> M_virus_locations;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
vector<vector<int>> map;
int ans = INT_MAX;
int zero_cnt = 0;
// N = 연구소의 크기, M = 바이러스의 개수

void solve()
{
    queue<pair<int, int>> q;
    vector<vector<int>> time(N, vector<int>(N, -1));
    int curr_ans = 0;
    int virus_cnt = 0;
    for (int i = 0; i < M_virus_locations.size(); i++)
    {
        int x = M_virus_locations[i].first;
        int y = M_virus_locations[i].second;
        q.push(make_pair(x, y));
        time[x][y] = 0;
    }
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (min(nx, ny) >= 0 and nx < N and ny < N)
            {
                if (map[nx][ny] != 1 and time[nx][ny] == -1)
                {
                    time[nx][ny] = time[x][y] + 1;
                    if (map[nx][ny] == 0)
                    {
                        virus_cnt++;
                        curr_ans = time[nx][ny];
                    }
                    q.push({nx, ny});
                }
            }
        }
    }
    if (virus_cnt == zero_cnt)
    {
        ans = min(curr_ans, ans);
    }
}

void choose_virus(int Cnt, int i)
{
    if (Cnt == M)
    {
        solve();
        return;
    }
    for (int index = i; index < virus_locations.size(); index++)
    {
        M_virus_locations.push_back(virus_locations[index]);
        choose_virus(Cnt + 1, index + 1);
        M_virus_locations.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    map.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                virus_locations.push_back({i, j});
            }
            if (map[i][j] == 0)
            {
                zero_cnt++;
            }
        }
    }
    choose_virus(0, 0);
    if (ans == INT_MAX)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ans << "\n";
    }
}