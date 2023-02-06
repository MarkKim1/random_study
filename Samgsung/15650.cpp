#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> result;
vector<int> temp;
void solve(int N, int M, int index)
{
    if (temp.size() == M)
    {
        result.push_back(temp);
        return;
    }
    for (int i = index; i <= N; i++)
    {
        temp.push_back(i);
        solve(N, M, i + 1);
        temp.pop_back();
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    solve(N, M, 1);
    for (auto a : result)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << "\n";
    }
}