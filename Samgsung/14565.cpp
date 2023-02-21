#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<vector<int>> vec;
vector<pair<int, int>> V;
int result = INT_MAX;
int find_distance()
{
    int ans = 0;
    for (auto h : house)
    {
        int x = h.first;
        int y = h.second;
        int closest = INT_MAX;
        for (auto c : V)
        {
            int xx = c.first;
            int yy = c.second;
            int dist = abs(x - xx) + abs(y - yy);
            closest = min(dist, closest);
        }
        ans += closest;
    }
    return ans;
}

void backtrack(int index)
{
    if (V.size() == M)
    {
        result = min(result, find_distance());
        return;
    }
    for (int i = index; i < chicken.size(); i++)
    {
        V.push_back(chicken[i]);
        backtrack(i + 1);
        V.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    vec.resize(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> vec[i][j];
            if (vec[i][j] == 1)
            {
                house.push_back({i, j});
            }
            if (vec[i][j] == 2)
            {
                chicken.push_back({i, j});
            }
        }
    }
    backtrack(0);
    cout << result << "\n";
}