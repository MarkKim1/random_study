// 이상한 피라미드 탐험

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

vector<vector<int>> pyramid;
unordered_map<int, pair<int, int>> map;
void make_pyramid()
{
    int row_count = 1;
    int total = 1;
    while (total < 10000)
    {
        vector<int> sub;
        for (int i = 0; i < row_count; i++)
        {
            sub.push_back(total);
            map[total] = make_pair(pyramid.size(), sub.size() - 1);
            total++;
            if (total > 10000)
            {
                break;
            }
        }
        pyramid.push_back(sub);
        if (total > 10000)
        {
            break;
        }
        row_count++;
    }
}
int BFS(pair<int, int> start, pair<int, int> end, int minji, int treasure)
{
    auto A = map[minji];
    auto B = map[minji];
    int a = 0, b = 0;
    while (A.first != end.first)
    {
        A = {A.first + 1, A.second};
        a++;
    }

    while (B.first != end.first)
    {
        B = {B.first + 1, B.second + 1};
        b++;
    }
    if (pyramid[A.first][A.second] <= treasure and treasure <= pyramid[B.first][B.second])
    {
        return min(a, b);
    }
    return min(abs(B.second - end.second), abs(A.second - end.second)) + min(a, b);
}

int main()
{
    int T;
    cin >> T;

    make_pyramid();

    for (int i = 0; i < T; i++)
    {
        int minji, treasure;
        cin >> minji >> treasure;

        if (minji == treasure)
        {
            printf("#%d %d\n", i + 1, 0);
            continue;
        }
        if (treasure < minji)
        {
            swap(minji, treasure);
        }
        auto start = map[minji];
        auto end = map[treasure];
        int result = BFS(start, end, minji, treasure);
        printf("#%d %d\n", i + 1, result);
    }
}
