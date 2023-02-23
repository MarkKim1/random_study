#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> vec;
vector<int> temp;
vector<vector<int>> result;

void solve(int index)
{
    if ((int)temp.size() == M)
    {
        result.push_back(temp);
        return;
    }
    for (int i = index; i < vec.size(); i++)
    {
        temp.push_back(vec[i]);
        solve(i);
        temp.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    solve(0);
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