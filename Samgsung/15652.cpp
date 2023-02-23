#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> vec;
vector<vector<int>> result;

void solve(int index)
{
    if ((int)vec.size() == M)
    {
        result.push_back(vec);
        return;
    }
    for (int i = index; i < N + 1; i++)
    {
        vec.push_back(i);
        solve(i);
        vec.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    solve(1);
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}