#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    vector<vector<int>> vec(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < N; i++)
    {
        vec[i][i] = 1;
    }
    for (int i = 0; i < N - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            vec[i][i + 1] = 1;
        }
    }
    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j + i < N; j++)
        {
            if (nums[j] == nums[i + j] and vec[j + 1][(j + i) - 1])
            {
                vec[j][j + i] = 1;
            }
        }
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        cout << vec[a - 1][b - 1] << "\n";
    }
}