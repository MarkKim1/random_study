#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
struct Point
{
    int x;
    int y;
};
vector<Point> points;
vector<int> visited;
int result = INT_MAX;
void Input(Point &company, Point &home)
{
    int var_count;
    cin >> var_count;
    cin >> company.x >> company.y;
    cin >> home.x >> home.y;
    for (int i = 0; i < var_count; i++)
    {
        Point p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }
    visited.assign(points.size(), 0);
}
int getDistance(Point &dist, Point p)
{
    return abs(dist.x - p.x) + abs(dist.y - p.y);
}
void DFS(int count, int curr_sum, Point dist, Point arrival)
{
    if (curr_sum > result)
        return;
    if (count == points.size())
    {
        int last = getDistance(dist, arrival);
        curr_sum += last;
        result = min(result, curr_sum);
        return;
    }
    for (int i = 0; i < points.size(); i++)
    {
        if (visited[i] != 0)
            continue;
        visited[i] = 1;
        int new_dist = getDistance(dist, points[i]);
        curr_sum += new_dist;
        DFS(count + 1, curr_sum, points[i], arrival);
        visited[i] = 0;
        curr_sum -= new_dist;
    }
}

void Solve(Point &company, Point &home)
{
    DFS(0, 0, company, home);
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        Point company;
        Point home;
        Input(company, home);
        Solve(company, home);
        printf("#%d %d", i + 1, result);
        cout << endl;
        result = INT_MAX;
        visited.clear();
        points.clear();
    }
}