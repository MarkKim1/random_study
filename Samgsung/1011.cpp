#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int a, b;
        cin >> a >> b;
        int distance = b - a;
        int A = sqrt(distance);
        int ans;
        if (pow(A, 2) == distance)
        {
            ans = A * 2 - 1;
        }
        else
        {
            ans = A * 2;
        }
        if (distance > A * (A + 1))
        {
            ans++;
        }
        cout << ans << "\n";
    }
}