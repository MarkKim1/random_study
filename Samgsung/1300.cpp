#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
long long N, K;

long long Count(long long mid)
{
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans += min(N, (long long)mid / i);
        if (i > mid)
        {
            break;
        }
    }
    return ans;
}

void solve()
{
    long long left = 1;
    long long right = N * N;
    long long res = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (Count(mid) < K)
        {
            left = mid + 1;
        }
        else
        {
            res = mid;
            right = mid - 1;
        }
    }
    cout << res << "\n";
}

int main()
{
    cin >> N >> K;
    solve();
}