#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int prison[3][101][101];
vector<vector<char>> map;
vector<pair<int, int>> prisoner;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int R, C;
struct INFO
{
    int r, c, count;
    bool operator<(const INFO &p2) const
    {
        return count > p2.count;
    }
};

void solve(int person_index, int r, int c)
{
    priority_queue<INFO> pq;
    prison[person_index][r][c] = 0;
    pq.push({r, c, 0});

    while (!pq.empty())
    {
        int curr_r = pq.top().r;
        int curr_c = pq.top().c;
        int curr_count = pq.top().count;
        pq.pop();
        if (curr_count > prison[person_index][curr_r][curr_c])
        {
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int next_r = curr_r + dx[i];
            int next_c = curr_c + dy[i];
            int next_count = curr_count;
            if (min(next_r, next_c) >= 0 and next_r <= R and next_c <= C)
            {
                if (map[next_r][next_c] == '*')
                {
                    continue;
                }
                if (map[next_r][next_c] == '#')
                {
                    next_count++;
                }
                if (next_count < prison[person_index][next_r][next_c])
                {
                    prison[person_index][next_r][next_c] = next_count;
                    pq.push({next_r, next_c, next_count});
                }
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> R >> C;
        map.resize(R + 2, vector<char>(C + 2, '.'));
        for (int i = 1; i < R + 1; i++)
        {
            for (int j = 1; j < C + 1; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == '$')
                {
                    prisoner.push_back({i, j});
                }
            }
        }
        memset(prison, 0xf, sizeof(prison));
        solve(0, 0, 0);
        solve(1, prisoner[0].first, prisoner[0].second);
        solve(2, prisoner[1].first, prisoner[1].second);
        int ans = INT_MAX;
        for (int i = 0; i <= R + 1; i++)
        {
            for (int j = 0; j <= C + 1; j++)
            {
                if (map[i][j] == '*')
                {
                    continue;
                }
                int curr_min = prison[0][i][j] + prison[1][i][j] + prison[2][i][j];
                if (map[i][j] == '#')
                {
                    curr_min -= 2;
                }
                ans = min(ans, curr_min);
            }
        }
        prisoner.clear();
        cout << "ans: " << ans << endl;
    }
}