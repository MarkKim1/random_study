#include <iostream>
#include <vector>

using namespace std;
#define MOD 1000000
#define P 1500000
int main()
{
    long long T;
    cin >> T;
    vector<long long> vec(P);
    vec[0] = 0;
    vec[1] = 1;
    for (int i = 2; i < P; i++)
    {
        vec[i] = (vec[i - 1] + vec[i - 2]) % MOD;
    }
    cout << vec[T % P];
}