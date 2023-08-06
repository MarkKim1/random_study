#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

char prison[102][102];
int min_door[3][102][102];
int height, width;
pair<int, int> prisoner[2];
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

void solve(int person_index, int r, int c)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    min_door[person_index][r][c] = 0;
    pq.push({0, {r, c}});

    while (!pq.empty())
    {
        int curr_r = pq.top().second.first;
        int curr_c = pq.top().second.second;
        int curr_count = pq.top().first;
        pq.pop();
        if (curr_count > min_door[person_index][curr_r][curr_c])
        {
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int next_r = curr_r + dx[i];
            int next_c = curr_c + dy[i];
            int next_count = curr_count;
            if (min(next_r, next_c) >= 0 and next_r < height + 2 and next_c < width + 2)
            {
                if (prison[next_r][next_c] == '*')
                {
                    continue;
                }
                if (prison[next_r][next_c] == '#')
                {
                    next_count++;
                }
                if (next_count < min_door[person_index][next_r][next_c])
                {
                    min_door[person_index][next_r][next_c] = next_count;
                    pq.push({next_count, {next_r, next_c}});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int test_num;
    cin >> test_num;

    while (test_num--)
    {
        cin >> height >> width;

        int order = 0;
        string st;
        for (int r = 1; r <= height; ++r)
        {
            cin >> st;
            st = '.' + st + '.';
            for (int c = 0; c <= width + 1; ++c)
            {
                prison[r][c] = st[c];
                if (prison[r][c] == '$')
                    prisoner[order++] = {r, c};
            }
        }

        for (int c = 0; c <= width + 1; ++c)
        {
            prison[0][c] = '.';
            prison[height + 1][c] = '.';
        }

        memset(min_door, 0xf, sizeof(min_door)); // 0xf로 초기화 해주자.
        solve(0, 0, 0);
        solve(1, prisoner[0].first, prisoner[0].second);
        solve(2, prisoner[1].first, prisoner[1].second);

        int min_open_num = INT32_MAX;
        int opened_doors;
        for (int r = 0; r <= height + 1; ++r)
        {
            for (int c = 0; c <= width + 1; ++c)
            {
                if (prison[r][c] == '*')
                    continue;

                opened_doors = min_door[0][r][c] + min_door[1][r][c] + min_door[2][r][c];
                if (prison[r][c] == '#') // 해당 좌표가 문인 경우
                    opened_doors -= 2;
                min_open_num = min(opened_doors, min_open_num);
            }
        }

        cout << min_open_num << '\n';
    }

    return 0;
}