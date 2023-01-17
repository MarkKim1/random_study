#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int curr = 0;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string A;
        cin >> A;
        if (A == "add")
        {
            int B;
            cin >> B;
            curr |= (1 << B);
        }
        if (A == "remove")
        {
            int B;
            cin >> B;
            curr &= ~(1 << B);
        }
        if (A == "check")
        {
            int B;
            cin >> B;
            if (curr & (1 << B))
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        if (A == "toggle")
        {
            int B;
            cin >> B;
            curr ^= (1 << B);
        }
        if (A == "all")
        {
            curr = 1 << 20;
            curr |= ~(1 << 20);
        }
        if (A == "empty")
        {
            curr = 0;
        }
    }
}