#include <iostream>
#include <vector>
#include <algorithm>

#define brk break
#define endl "\n"

using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int sum = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (sum < arr[i])
            break;
        sum += arr[i];
    }
    cout << sum << endl;
}