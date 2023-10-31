#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FISH
{
    int num;
    int x, y, dir;
    bool live;
};
vector<vector<int>> map(4, vector<int>(4));
vector<FISH> fish(20);

void COPY(vector<vector<int>> &C_MAP, vector<FISH> &C_FISH, vector<vector<int>> &map, vector<FISH> fish)
{
    int fishcount = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            map[i][j] = C_MAP[i][j];
            // C_FISH[fishcount++] = { map[i][j],i,j}
        }
    }
}

void solve()
{
    vector<vector<int>> C_MAP(4, vector<int>(4));
    vector<FISH> C_FISH(20);
    COPY(C_MAP, C_FISH, map, fish);
}

bool comp(FISH a, FISH b)
{
    return a.num < b.num;
}

int main()
{
    int fishcount = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a, b;
            cin >> a >> b;
            map[i][j] = a;
            fish[fishcount++] = {a, i, j, b, true};
        }
    }
    sort(fish.begin(), fish.end(), comp);
    solve();
}