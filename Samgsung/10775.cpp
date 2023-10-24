#include <iostream>
#include <vector>
using namespace std;
int p[100001];

int find(int a)
{
    if (a == p[a])
        return a;
    else
        return p[a] = find(p[a]);
}

bool Union(int x, int y)
{
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty)
    {
        p[rootx] = rooty;
        return true;
    }
    return false;
}

int main()
{
    int G, P;
    int ans = 0;
    cin >> G >> P;
    for (int i = 0; i <= G; i++)
    {
        p[i] = i;
    }
    while (P--)
    {
        int g;
        cin >> g;
        int a = find(g);
        if (a == 0)
            break;
        Union(a, a - 1);
        ans++;
    }
    cout << ans << "\n";
}