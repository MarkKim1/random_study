#include <iostream>
#include <vector>

using namespace std;

class UnionFind
{
public:
    vector<int> vec;
    UnionFind(int x)
    {
        vec.resize(x);
        for (int i = 0; i < x; i++)
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
            return true;
        }
        vec[rooty] = rootx;
        return false;
    }
    int find(int a)
    {
        if (vec[a] == a)
        {
            return a;
        }
        return vec[a] = find(vec[a]);
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    UnionFind *uf = new UnionFind(N);
    int cnt = 0;
    bool is_cycle = false;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cnt++;
        if (uf->Union(a, b))
        {
            is_cycle = true;
            break;
        }
    }
    if (is_cycle)
        cout << cnt << "\n";
    else
        cout << 0 << "\n";
}