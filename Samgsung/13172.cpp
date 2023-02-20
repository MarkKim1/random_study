// 페르마의 소정리를 이해해야 풀수 있는 문제
// a^n+m = a^n * a^m
#include <iostream>
#include <numeric>
using namespace std;
const long long MOD = 1000000007;

long long power(long long b, long long y)
{
    if (y == 1)
    {
        return b;
    }
    if (y % 2 == 1)
    {
        return b * power(b, y - 1) % MOD;
    }
    long long p = power(b, y / 2) % MOD;
    return p * p % MOD;
}

int main()
{
    long long ans = 0;
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        long long b, c;
        cin >> b >> c;
        ans += (c * power(b, MOD - 2)) % MOD;
    }
    cout << ans % MOD << "\n";
}