#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void UnionFind(int x, int y)
{
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty)
    {
        parent[rooty] = rootx;
    }
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> know;

    vector<vector<int>> vec(M);
    for (int i = 0; i < K; i++)
    {
        int A;
        cin >> A;
        know.push_back(A);
    }
    for (int i = 0; i <= N; i++)
    {
        parent.push_back(i);
    }
    for (int i = 0; i < M; i++)
    {
        int count;
        cin >> count;
        int num;
        int prev;
        for (int j = 0; j < count; j++)
        {
            if (j == 0)
            {
                cin >> num;
            }
            else
            {
                prev = num;
                cin >> num;
                UnionFind(prev, num);
            }
            vec[i].push_back(num);
        }
    }
    for (auto party : vec)
    {
        bool flag = false;
        for (auto person : party)
        {
            if (flag)
                break;
            for (auto each : know)
            {
                if (find(person) == find(each))
                {
                    flag = true;
                    M--;
                    break;
                }
            }
        }
    }
    cout << M << "\n";
}