#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int const MAX = 4000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> arr(4, vector<int>(N, 0));
    vector<int> AB;
    vector<int> CD;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[j][i];
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // cout << endl;
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            AB.push_back(arr[0][i] + arr[1][j]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            CD.push_back(arr[2][i] + arr[3][j]);
        }
    }
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    int left = 0;
    int right = CD.size() - 1;
    long long ans = 0;

    while (left < AB.size() and right >= 0)
    {
        if (AB[left] + CD[right] == 0)
        {
            int original = left;
            long long AB_count = 0;
            long long CD_count = 0;
            while (left < AB.size() and AB[left] + CD[right] == 0)
            {
                left++;
                AB_count++;
            }

            while (right >= 0 and AB[original] + CD[right] == 0)
            {
                CD_count++;
                right--;
            }
            ans = ans + (AB_count * CD_count);
        }
        else if (AB[left] + CD[right] > 0)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    cout << ans << "\n";
}