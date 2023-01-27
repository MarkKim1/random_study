#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
bool col[300];
bool dig[300];    // "/"
bool disdig[300]; // "\"
int result = 0;
int T;

void solve(int start)
{

    if (start >= T)
    {
        result++;
        return;
    }

    for (int i = 0; i < T; i++)
    {
        if (col[i] || dig[i + start] || disdig[T + i - start])
        {
            continue;
        }
        col[i] = true;
        dig[i + start] = true;
        disdig[T + i - start] = true;

        solve(start + 1);

        col[i] = false;
        dig[i + start] = false;
        disdig[T + i - start] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    solve(0);
    cout << result << "\n";
}