#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> LIS;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (LIS.empty() || LIS.back() < arr[i])
        {
            LIS.push_back(arr[i]);
        }
        else
        {
            int pos = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
            LIS[pos] = arr[i];
        }
    }

    cout << LIS.size() << endl;
}