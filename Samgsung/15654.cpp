#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> result;
vector<int> temp;
vector<int> container;
int N, M;
void solve(vector<int> &visited)
{
    if ((int)temp.size() == M)
    {
        result.push_back(temp);
        return;
    }
    for (int i = 0; i < container.size(); i++)
    {
        if (visited[i] == 0)
        {
            temp.push_back(container[i]);
            visited[i] = 1;
            solve(visited);
            temp.pop_back();
            visited[i] = 0;
        }
    }
}

int main()
{

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        container.push_back(A);
    }
    sort(container.begin(), container.end());
    vector<int> visited(N);
    solve(visited);
    for (auto a : result)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << "\n";
    }
}