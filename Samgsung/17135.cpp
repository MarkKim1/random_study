#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int OriginMap[16][16];
int map[16][16];
int N, M, D;
int answer = 0;
vector<int> archerCol;

void input()
{
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> OriginMap[i][j];
            map[i][j] = OriginMap[i][j];
        }
    }
}

void MapCopy()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            map[i][j] = OriginMap[i][j];
        }
    }
}

int distance(int a, int b, int c, int d)
{
    return abs(a - c) + abs(b - d);
}

struct T
{
    int a, b, c;
};

bool cmp(T &x, T &y)
{
    if (x.c == y.c)
        return x.b < y.b;
    else
        return x.c < y.c;
}

int solve()
{
    int archerRow = N;
    int ret = 0;
    while (archerRow >= 1)
    {
        vector<pair<int, int>> ex;
        for (auto col : archerCol)
        {
            vector<T> target;
            for (int r = 0; r < archerRow; r++)
            {
                for (int c = 0; c < M; c++)
                {
                    int Dist = distance(r, c, archerRow, col);
                    if (map[r][c] == 1 and Dist <= D)
                    {
                        target.push_back({r, c, Dist});
                    }
                }
            }
            if (target.empty())
            {
                continue;
            }
            sort(target.begin(), target.end(), cmp);
            ex.push_back({target[0].a, target[0].b});
        }
        for (auto each : ex)
        {
            if (map[each.first][each.second] == 1)
            {
                map[each.first][each.second] = 0;
                ret++;
            }
        }
        archerRow--;
    }
    return ret;
}

void archer(int i, int Cnt)
{
    if (Cnt == 3)
    {
        MapCopy();
        answer = max(answer, solve());
        return;
    }
    for (int index = i; index < M; index++)
    {
        archerCol.push_back(index);
        archer(index + 1, Cnt + 1);
        archerCol.pop_back();
    }
}

int main()
{
    input();
    archer(0, 0);
    cout << answer << "\n";
}