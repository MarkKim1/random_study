#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec, res;
int Cnt = 1;

int myLower(int target)
{
    int left = 0;
    int right = res.size() - 1;
    int mid = right;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (res[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

void solve()
{
    res.push_back(vec[0]);
    for (int i = 1; i < vec.size(); i++)
    {
        if (res.back() < vec[i])
        {
            res.push_back(vec[i]);
            Cnt++;
        }
        else
        {
            int index = myLower(vec[i]);
            res[index] = vec[i];
        }
    }
}

int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    solve();
    cout << Cnt << "\n";
}