#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> vec(T + 1);
    vec[2] = 1;
    vec[3] = 1;
    for (int i = 4; i <= T; i++)
    {
        int a = INT_MAX;
        int b = INT_MAX;
        int c = INT_MAX;
        if (i % 3 == 0)
        {
            a = vec[3] + vec[i / 3];
        }
        if (i % 2 == 0)
        {
            b = vec[2] + vec[i / 2];
        }
        c = vec[i - 1] + 1;
        vec[i] = min(a, min(b, c));
    }
    cout << vec[T] << endl;
}