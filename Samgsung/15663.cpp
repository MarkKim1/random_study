#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> vec;
vector<int> temp;
vector<vector<int>> result;
bool visited[9] = {
    false,
};
void solve()
{
    if ((int)temp.size() == M)
    {
        result.push_back(temp);
        return;
    }
    int x = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (x != vec[i] and !visited[i])
        {
            x = vec[i];
            visited[i] = true;
            temp.push_back(vec[i]);
            solve();
            temp.pop_back();
            visited[i] = false;
        }
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
    solve();
    for (auto a : result)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << "\n";
    }
}