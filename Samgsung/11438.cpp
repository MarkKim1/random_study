#include <iostream>
#include <vector>
#include <unordered_map>
unordered_map<int, vector<int>> nodes;
using namespace std;
int parent[100001][18];
int depth[100001];
int N, M;
int max_height;

void make(int pre, int now, int dep)
{
    if (nodes[now].empty())
    {
        return;
    }
    parent[now][0] = pre;
    depth[now] = dep;
    for (int i = 0; i < nodes[now].size(); i++)
    {
        if (nodes[now][i] != pre)
        {
            make(now, nodes[now][i], dep + 1);
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    make(0, 1, 0);
    cin >> M;
    int temp = N, cnt = 0;
    while (temp > 1)
    {
        temp = temp >> 1;
        cnt++;
    }
    max_height = temp;
    for (int height = 1; height <= max_height; height++)
    {
        for (int node_num = 2; node_num <= N; node_num++)
        {
            if (parent[node_num][height - 1] != 0)
            {
                parent[node_num][height] = parent[parent[node_num][height - 1]][height - 1];
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
    }
}