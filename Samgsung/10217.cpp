#include <iostream>
#include <vector>

using namespace std;
int N, M, K;

struct INFO
{
    int TO, COST, TIME;
};

vector<vector<INFO>> map;
int dp[10001][101];

int KCM(int curr_money, int curr_node)
{
    if (dp[curr_money][curr_node] != -1)
    {
        return dp[curr_money][curr_node];
    }
    if (curr_node == N)
    {
        return 0;
    }
    dp[curr_money][curr_node] = 100000000;
    for (auto each : map[curr_node])
    {
        if (each.COST <= curr_money)
        {
            dp[curr_money][curr_node] = min(dp[curr_money][curr_node], KCM(curr_money - each.COST, each.TO) + each.TIME);
        }
    }
    return dp[curr_money][curr_node];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    cin >> N >> M >> K;
    fill(&dp[0][0], &dp[10000][100], -1);
    map.resize(N + 1);
    for (int i = 0; i < K; i++)
    {
        int from, to, cost, time;
        cin >> from >> to >> cost >> time;
        map[from].push_back({to, cost, time});
    }
    int ans = KCM(M, 1);
    if (ans == 100000000)
    {
        cout << "Poor KCM"
             << "\n";
    }
    else
    {
        cout << ans << "\n";
    }
}