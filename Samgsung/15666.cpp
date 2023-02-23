#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> vec;
vector<int> temp;
vector<vector<int>> result;
vector<bool> visited(9);
void solve(int index)
{
    if ((int)temp.size() == M)
    {
        sort(temp.begin(), temp.end());
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
    vector<int> temp = result[0];
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i < result.size(); i++)
    {
        if (temp == result[i])
        {
            continue;
        }
        else
        {
            temp = result[i];
            for (int i = 0; i < temp.size(); i++)
            {
                cout << temp[i] << " ";
            }
            cout << "\n";
        }
    }
}