#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class unionFind
{
public:
    vector<int> vec;
    unionFind(int x)
    {
        vec.resize(x + 1);
        for (int i = 1; i <= x; i++)
        {
            vec[i] = i;
        }
    }
    bool Union(int a, int b)
    {
        int rootx = find(a);
        int rooty = find(b);
        if (rootx == rooty)
        {
            return false;
        }
        vec[rooty] = rootx;
        return true;
    }
    int find(int x)
    {
        if (vec[x] == x)
        {
            return x;
        }
        return vec[x] = find(vec[x]);
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, pair<int, int>>> graph;
    unionFind *UF = new unionFind(N);
    vector<int> ans;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }
    sort(graph.begin(), graph.end());
    for (int i = 0; i < graph.size(); i++)
    {
        if (UF->find(graph[i].second.first) != UF->find(graph[i].second.second))
        {
            UF->Union(graph[i].second.first, graph[i].second.second);
            ans.push_back(graph[i].first);
        }
    }
    int result = 0;
    for (int i = 0; i < ans.size() - 1; i++)
    {
        result += ans[i];
    }
    cout << result << "\n";
}