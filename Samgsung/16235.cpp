#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits.h>
using namespace std;
unordered_map<int, unordered_map<int, priority_queue<int, vector<int>, greater<>>>> tree;
vector<pair<int, int>> tree_location;
vector<vector<int>> board;
vector<vector<int>> dead_tree_location;
vector<vector<int>> S2D2;
vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
int N, M, K;
void spring()
{
    unordered_map<int, unordered_map<int, vector<int>>> tree_to_add;
    for (int i = 0; i < tree_location.size(); i++)
    {
        int r = tree_location[i].first;
        int c = tree_location[i].second;
        while (!tree[r][c].empty() and board[r][c] >= tree[r][c].top())
        {
            int curr_tree = tree[r][c].top();
            tree[r][c].pop();
            board[r][c] -= curr_tree;
            curr_tree++;
            tree_to_add[r][c].push_back(curr_tree);
        }
        while (!tree[r][c].empty())
        {
            dead_tree_location[r][c] += (tree[r][c].top() / 2);
            tree[r][c].pop();
        }
        for (int i = 0; i < tree_to_add[r][c].size(); i++)
        {
            tree[r][c].push(tree_to_add[r][c][i]);
            // cout << tree_to_add[r][c][i] << "\n";
        }
    }
    vector<pair<int, int>> temp;
    for (int i = 0; i < tree_location.size(); i++)
    {
        int r = tree_location[i].first;
        int c = tree_location[i].second;
        if (!tree[r][c].empty())
        {
            temp.push_back({r, c});
        }
    }
    tree_location = temp;
}

void summer()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            board[i][j] += dead_tree_location[i][j];
        }
    }
    dead_tree_location.resize(N + 1, vector<int>(N + 1, 0));
}

void fall()
{
    vector<pair<int, int>> temp_location;
    for (int i = 0; i < tree_location.size(); i++)
    {
        int r = tree_location[i].first;
        int c = tree_location[i].second;
        vector<int> temp;
        while (!tree[r][c].empty())
        {
            if (tree[r][c].top() % 5 == 0)
            {
                for (int j = 0; j < dx.size(); j++)
                {
                    int new_r = dx[j] + r;
                    int new_c = dy[j] + c;
                    if (min(new_r, new_c) >= 1 and new_r <= N and new_c <= N)
                    {
                        if (tree[new_r][new_c].empty())
                        {
                            temp_location.push_back({new_r, new_c});
                        }
                        tree[new_r][new_c].push(1);
                    }
                }
            }
            temp.push_back(tree[r][c].top());
            tree[r][c].pop();
        }
        for (int a = 0; a < temp.size(); a++)
        {
            tree[r][c].push(temp[a]);
        }
    }
    for (int i = 0; i < temp_location.size(); i++)
    {
        tree_location.push_back(temp_location[i]);
    }
}

void winter()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            board[i][j] += S2D2[i][j];
        }
    }
}
int main()
{
    cin >> N >> M >> K;
    board.resize(N + 1, vector<int>(N + 1));
    dead_tree_location.resize(N + 1, vector<int>(N + 1));
    S2D2.resize(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int a;
            cin >> a;
            board[i][j] = 5;
            S2D2[i][j] = a;
        }
    }
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a][b].push(c);
        tree_location.push_back({a, b});
    }
    for (int i = 0; i < K; i++)
    {
        spring();
        summer();
        fall();
        winter();
    }
    int ans = 0;
    for (int i = 0; i < tree_location.size(); i++)
    {
        int r = tree_location[i].first;
        int c = tree_location[i].second;
        if (tree[r].find(c) != tree[r].end())
        {
            ans += tree[r][c].size();
        }
    }
    cout << ans << "\n";
}