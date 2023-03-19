#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector<pair<double, double>> coords;
vector<pair<double, pair<double, double>>> graph;

class DSU
{
public:
    vector<int> root;
    DSU(int x)
    {
        for (int i = 0; i < x; i++)
        {
            root.push_back(i);
        }
    }
    bool Union(int a, int b)
    {
        int rootx = find(a);
        int rooty = find(b);
        if (rootx == rooty)
        {
            return true;
        }
        else
        {
            root[rooty] = rootx;
        }
        return false;
    }
    int find(int x)
    {
        if (root[x] == x)
        {
            return x;
        }
        return root[x] = find(root[x]);
    }
};

double find_distance(int i, int j)
{
    double x1 = coords[i].first;
    double y1 = coords[i].second;
    double x2 = coords[j].first;
    double y2 = coords[j].second;
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        double a, b;
        cin >> a >> b;
        coords.push_back({a, b});
    }
    for (int i = 0; i < coords.size(); i++)
    {
        for (int j = i + 1; j < coords.size(); j++)
        {
            double dist = find_distance(i, j);
            graph.push_back(make_pair(dist, make_pair(i, j)));
        }
    }
    sort(graph.begin(), graph.end());
    DSU *dsu = new DSU(N);
    double ans = 0;
    for (auto each : graph)
    {
        if (!dsu->Union(each.second.first, each.second.second))
        {
            ans += each.first;
        }
    }
    printf("%.2lf\n", ans);
}