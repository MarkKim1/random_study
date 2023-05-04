#include <iostream>
#include <vector>

using namespace std;
int T;
void color_blind(int i, int j, vector<vector<char>> &map)
{
    if (min(i, j) < 0 || i >= T || j >= T || (map[i][j] != 'R' and map[i][j] != 'G'))
    {
        return;
    }
    map[i][j] = '@';
    color_blind(i + 1, j, map);
    color_blind(i - 1, j, map);
    color_blind(i, j + 1, map);
    color_blind(i, j - 1, map);
}

void solve(int i, int j, vector<vector<char>> &map, char curr)
{
    if (min(i, j) < 0 || i >= T || j >= T || map[i][j] != curr)
    {
        return;
    }
    map[i][j] = '@';
    solve(i + 1, j, map, curr);
    solve(i - 1, j, map, curr);
    solve(i, j + 1, map, curr);
    solve(i, j - 1, map, curr);
}

int main()
{
    cin >> T;
    vector<vector<char>> original(T, vector<char>(T));
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            cin >> original[i][j];
        }
    }
    vector<vector<char>> map = original;
    int first = 0, second = 0;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            if (map[i][j] != '@')
            {
                first++;
                solve(i, j, map, map[i][j]);
            }
        }
    }
    map = original;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            if (map[i][j] != '@')
            {
                if (map[i][j] == 'B')
                {
                    second++;
                    solve(i, j, map, map[i][j]);
                }
                else
                {
                    second++;
                    color_blind(i, j, map);
                }
            }
        }
    }
    cout << first << " " << second << "\n";
}