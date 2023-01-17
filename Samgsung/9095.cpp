#include <iostream>
using namespace std;

int solve(int A)
{
    if (A == 0)
    {
        return 1;
    }
    if (A < 0)
    {
        return 0;
    }
    return solve(A - 1) + solve(A - 2) + solve(A - 3);
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int A;
        cin >> A;
        cout << solve(A) << endl;
    }
}