#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int N, T;
void floyd_warshall(vector<vector<int>> &vec)
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                {
                    vec[i][j] = 0;
                    continue;
                }
                if (vec[i][k] != INT_MAX and vec[k][j] != INT_MAX)
                {
                    vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
                }
            }
        }
    }
}

int main()
{

    cin >> N >> T;
    vector<vector<int>> vec(N + 1, vector<int>(N + 1, INT_MAX));
    for (int i = 0; i < T; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        vec[A][B] = min(vec[A][B], C);
    }
    floyd_warshall(vec);
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = 1; j < vec[i].size(); j++)
        {
            if (vec[i][j] == INT_MAX)
            {
                cout << 0 << " ";
                continue;
            }
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
}