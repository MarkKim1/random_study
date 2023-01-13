#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
public:
    vector<int> graph;
    UnionFind(int x)
    {
        for (int i = 0; i < x; i++)
        {
            graph.push_back(i);
        }
    }
    void Union(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
        {
            graph[rooty] = rootx;
        }
    }
    int find(int x)
    {
        if (graph[x] == x)
        {
            return x;
        }
        return graph[x] = find(graph[x]);
    }
};

int main()
{
    int T, K;
    cin >> T >> K;
    UnionFind *uf = new UnionFind(T + 1);
    for (int i = 0; i < K; i++)
    {
        int A, B;
        cin >> A >> B;
        uf->Union(A, B);
    }
    int result = 0;
    for (int i = 2; i <= T; i++)
    {
        if (uf->find(i) == uf->find(1))
        {
            result++;
        }
    }
    cout << result << endl;
}