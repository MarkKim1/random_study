#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int N, S;
    cin >> N >> S;
    int vec[N];
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    long long result = INT_MAX;
    int pos = 0;
    long long curr = 0;
    for (int i = 0; i < N; i++)
    {
        curr += vec[i];
        while (curr >= S and pos <= i)
        {
            curr -= vec[pos];
            result = min(result, ((long long)i - pos) + 1);
            pos++;
        }
    }
    cout << (result == INT_MAX ? 0 : result) << "\n";
}