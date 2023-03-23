#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 100001;
int graph[MAX], done[MAX], visited[MAX];
int cnt = 0;

void solve(int curr_node)
{
    visited[curr_node] = true;
    int next = graph[curr_node];
    if (!visited[next])
    {
        solve(next);
    }
    else if (!done[next])
    {
        for (int i = next; i != curr_node; i = graph[i])
        {
            cnt++;
        }
        cnt++;
    }
    done[curr_node] = true;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> graph[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                solve(i);
            }
        }
        cout << n - cnt << "\n";
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
        memset(graph, 0, sizeof(graph));
        cnt = 0;
    }
}