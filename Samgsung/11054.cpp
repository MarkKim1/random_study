#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> vec(T);
    vector<int> L(T, 0);
    vector<int> R(T, 0);
    for (int i = 0; i < T; i++)
    {
        cin >> vec[i];
    }

    for (int i = 1; i < T; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec[i] > vec[j])
            {
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }

    for (int i = T - 2; i >= 0; i--)
    {
        for (int j = T - 1; j > i; j--)
        {
            if (vec[i] > vec[j])
            {
                R[i] = max(R[i], R[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < T; i++)
    {
        ans = max(ans, L[i] + R[i] + 1);
        // cout << L[i] << " ";
    }
    // cout << endl;
    // for (int i = 0; i < T; i++)
    // {
    //     cout << R[i] << " ";
    // }
    // cout << endl;
    cout << ans << "\n";
}