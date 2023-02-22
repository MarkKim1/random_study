#include <iostream>
#include <vector>
using namespace std;
int R, C, T;
int main()
{
    cin >> R >> C >> T;
    vector<vector<int>> room(R, vector<int>(C));
    vector<vector<int>> add(R, vector<int>(C));
    vector<int> x = {0, 1, 0, -1};
    vector<int> y = {1, 0, -1, 0};
    vector<pair<int, int>> vacuum;
    int result = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> room[i][j];
            if (room[i][j] == -1)
            {
                vacuum.push_back({i, j});
            }
        }
    }
    // 1. 미세먼지 양 만큼 미세먼지를 퍼지게한다.
    // 2. 퍼진 미세먼지를 공기청정기로 청소한다.
    // 3. 2번이 끝나면 1초가 지나므로 1로 다시 돌아간다.
    while (T--)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                int cnt = 0;
                int val = room[i][j] / 5;
                if (room[i][j] == 0 || room[i][j] == -1)
                    continue;
                for (int k = 0; k < 4; k++)
                {
                    int nr = i + x[k];
                    int nc = j + y[k];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                        continue;
                    if (room[nr][nc] == -1)
                        continue;
                    add[nr][nc] += val;
                    cnt++;
                }
                add[i][j] -= (cnt * val);
            }
        }

        // 미세먼지 확산 업데이트
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                room[i][j] += add[i][j];
                add[i][j] = 0;
            }
        }
        for (int index = 0; index < 2; index++)
        {
            if (index == 0)
            {
                for (int i = vacuum[index].first - 1; i > 0; i--)
                {
                    room[i][0] = room[i - 1][0];
                }
                for (int i = 0; i < C - 1; i++)
                {
                    room[0][i] = room[0][i + 1];
                }
                for (int i = 0; i < vacuum[index].first; i++)
                {
                    room[i][C - 1] = room[i + 1][C - 1];
                }
                for (int i = C - 1; i > 1; i--)
                {
                    room[vacuum[index].first][i] = room[vacuum[index].first][i - 1];
                }
                room[vacuum[index].first][1] = 0;
            }
            else
            {
                for (int i = vacuum[index].first + 1; i < R - 1; i++)
                {
                    room[i][0] = room[i + 1][0];
                }
                for (int i = 0; i < C - 1; i++)
                {
                    room[R - 1][i] = room[R - 1][i + 1];
                }
                for (int i = R - 1; i >= vacuum[index].first; i--)
                {
                    room[i][C - 1] = room[i - 1][C - 1];
                }
                for (int i = C - 1; i > 1; i--)
                {
                    room[vacuum[index].first][i] = room[vacuum[index].first][i - 1];
                }
                room[vacuum[index].first][1] = 0;
            }
        }
        if (T == 0)
        {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    result += room[i][j];
                }
            }
        }
    }
    cout << result + 2 << "\n";
}