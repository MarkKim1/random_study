#include <iostream>
#include <vector>

using namespace std;

void solve(int from, int mid, int to, int N)
{
    if (N == 1)
    {
        cout << from << " " << to << "\n";
    }
    else
    {
        solve(from, to, mid, N - 1);
        cout << from << " " << to << "\n";
        solve(mid, from, to, N - 1);
    }
}

int CNT(int N)
{
    int num = 1;
    for (int i = 0; i < N; i++)
    {
        num *= 2;
    }
    return num - 1;
}

int main()
{
    int N;
    cin >> N;
    int k = CNT(N);
    cout << k << "\n";
    solve(1, 2, 3, N);
}