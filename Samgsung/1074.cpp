#include <iostream>
#include <vector>
using namespace std;
int result = 0;
int A, B;
bool solve(int x, int y, int N)
{
    if (x == A and y == B)
    {
        return true;
    }
    if (A < x + N && A >= x && B < y + N && B >= y)
    {
        if (solve(x, y, N / 2) ||
            solve(x, y + (N / 2), N / 2) ||
            solve(x + (N / 2), y, N / 2) ||
            solve(x + (N / 2), y + (N / 2), N / 2))
        {
            return true;
        }
    }
    else
    {
        result += N * N;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    int N = 1 << T;
    cin >> A >> B;
    if (solve(0, 0, N))
    {
        cout << result << "\n";
    }
}
