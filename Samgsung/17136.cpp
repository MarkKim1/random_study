#include <iostream>
#include <vector>

using namespace std;

int result = 100;
vector<vector<int>> map(10, vector<int>(10));
vector<int> paper = {5, 5, 5, 5, 5};
bool fill_check()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

void change(int a, int b, int c, bool state)
{
    for (int i = a; i <= a + c; i++)
    {
        for (int j = b; j <= b + c; j++)
        {
            map[i][j] = state;
        }
    }
}

bool check(int a, int b, int c)
{
    for (int i = a; i <= a + c; i++)
    {
        for (int j = b; j <= b + c; j++)
        {
            if (map[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void solve(int cnt)
{
    if (result < cnt)
    {
        return;
    }
    if (fill_check())
    {
        result = min(result, cnt);
        return;
    }
    for (int a = 0; a < 10; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            if (map[a][b] == 1)
            {
                for (int c = 4; c >= 0; c--)
                {
                    if (paper[c] > 0 and a + c < 10 and b + c < 10 and check(a, b, c))
                    {
                        paper[c]--;
                        change(a, b, c, 0);

                        solve(cnt + 1);

                        paper[c]++;
                        change(a, b, c, 1);
                    }
                }
                return;
            }
        }
    }
}

int main()
{

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> map[i][j];
        }
    }
    solve(0);
    result == 100 ? cout << -1 << "\n" : cout << result << "\n";
}