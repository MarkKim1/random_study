#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
vector<vector<char>> map;
int ans = 0;
int R, C;

vector<int> x = {-1, 0, 1};
vector<int> y = {1, 1, 1};

bool solve(int row, int col)
{
    if (col == C - 1)
    {
        ans++;

        return true;
    }
    for (int i = 0; i < 3; i++)
    {
        int n_row = row + x[i];
        int n_col = col + y[i];
        if (min(n_row, n_col) >= 0 and n_row < R and n_col < C and map[n_row][n_col] != 'x')
        {
            map[n_row][n_col] = 'x';
            if (solve(n_row, n_col))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    cin >> R >> C;
    map.resize(R, vector<char>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < R; i++)
    {
        solve(i, 0);
    }
    cout << ans << "\n";
}