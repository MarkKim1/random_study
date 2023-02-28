#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long vec[N];
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    int left = 0;
    int right = N - 1;
    long long comp = INT_MAX;
    pair<long long, long long> result = {0, 0};
    while (left < right)
    {
        long long temp = vec[left] + vec[right];
        if (comp > abs(temp))
        {
            comp = abs(temp);
            result.first = vec[left], result.second = vec[right];
        }
        if (temp < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << result.first << " " << result.second << "\n";
}