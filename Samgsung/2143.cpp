#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long T, N, M;
    vector<long long> v1, v2;
    vector<long long> sum1, sum2;
    cin >> T;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        v2.push_back(a);
    }
    long long curr = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        curr = v1[i];
        sum1.push_back(curr);
        for (int j = i + 1; j < v1.size(); j++)
        {
            curr += v1[j];
            sum1.push_back(curr);
        }
    }
    curr = 0;
    for (int i = 0; i < v2.size(); i++)
    {
        curr = v2[i];
        sum2.push_back(curr);
        for (int j = i + 1; j < v2.size(); j++)
        {
            curr += v2[j];
            sum2.push_back(curr);
        }
    }
    long long ans = 0;
    sort(sum2.begin(), sum2.end());
    for (auto each : sum1)
    {
        int upper = upper_bound(sum2.begin(), sum2.end(), T - each) - v2.begin();
        int lower = lower_bound(sum2.begin(), sum2.end(), T - each) - v2.begin();
        ans += upper - lower;
    }
    cout << ans << "\n";
}
