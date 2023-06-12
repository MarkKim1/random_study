#include <iostream>
#include <vector>
#include <algorithm>
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
bool union_find(int a, int b)
{
    int n_a = find(a);
    int n_b = find(b);
    if (n_a != n_b)
    {
        parent[n_b] = n_a;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<pair<int, int>> X;
    vector<pair<int, int>> Y;
    vector<pair<int, int>> Z;
    vector<pair<int, pair<int, int>>> INFO;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        parent.push_back(i);
    }
    for (int i = 0; i < T; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        X.push_back({a, i});
        Y.push_back({b, i});
        Z.push_back({c, i});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 0; i < T - 1; i++)
    {
        INFO.push_back({X[i + 1].first - X[i].first, {X[i + 1].second, X[i].second}});
        INFO.push_back({Y[i + 1].first - Y[i].first, {Y[i + 1].second, Y[i].second}});
        INFO.push_back({Z[i + 1].first - Z[i].first, {Z[i + 1].second, Z[i].second}});
    }
    sort(INFO.begin(), INFO.end());
    int ans = 0;
    for (int i = 0; i < INFO.size(); i++)
    {
        int a = INFO[i].second.first;
        int b = INFO[i].second.second;
        int distance = INFO[i].first;
        if (union_find(a, b))
        {
            ans += distance;
        }
    }
    cout << ans << "\n";
}