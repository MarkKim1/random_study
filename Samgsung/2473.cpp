#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
vector<long long> vec;

long long first, second, third;
long long temp = LLONG_MAX;

void solve(long long f, int i)
{
    int left = i;
    int right = vec.size() - 1;
    while (left < right)
    {
        long long a = f + vec[left] + vec[right];
        if (abs(a) < abs(temp))
        {
            temp = a;
            first = f;
            second = vec[left];
            third = vec[right];
        }
        if (a > 0)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    vec.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < N - 2; i++)
    {
        solve(vec[i], i + 1);
    }
    cout << first << " " << second << " " << third << "\n";
}