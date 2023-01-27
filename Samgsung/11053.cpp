#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> vec;
    vector<int> dp(T, 1);
    for (int i = 0; i < T; i++)
    {
        int A;
        cin >> A;
        vec.push_back(A);
    }
    int result = 1;
    for (int i = vec.size() - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[i] < vec[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                result = max(dp[i], result);
            }
        }
    }
    cout << result << "\n";
}