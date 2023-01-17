#include <iostream>
#include <vector>
using namespace std;

class DSU
{
public:
    vector<int> vertex;
    DSU(int x)
    {
        for (int i = 0; i < x; i++)
        {
            vertex.push_back(i);
        }
    }
    void Union(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
        {
            vertex[rooty] = rootx;
        }
    }
    int find(int x)
    {
        if (x == vertex[x])
        {
            return x;
        }
        return vertex[x] = find(vertex[x]);
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    DSU dsu(N + 1);
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        dsu.Union(A, B);
    }
    int result = 0;
    for (int i = 1; i < dsu.vertex.size(); i++)
    {
        dsu.find(i);
        if (dsu.vertex[i] == i)
        {
            result++;
        }
    }
    cout << result << "\n";
}