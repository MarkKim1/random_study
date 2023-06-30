#include <iostream>
#include <vector>
#include <queue>
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int main()
{
    _ int N, L;
    cin >> N >> L;
    vector<int> arr(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    deque<pair<int, int>> dq;
    for (int i = 1; i <= N; i++)
    {
        if (!dq.empty())
        {
            if (dq.front().second < i - L + 1)
            {
                dq.pop_front();
            }
        }
        while (!dq.empty() and dq.back().first > arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(make_pair(arr[i], i));
        cout << dq.front().first << " ";
    }
    cout << "\n";

    return 0;
}