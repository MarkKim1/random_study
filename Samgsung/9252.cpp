#include <iostream>
#include <string>
using namespace std;
int board[1001][1001];
string s1, s2;

void print(int i, int j)
{
    if (board[i][j] == 0)
    {
        return;
    }
    if (s1[i - 1] == s2[j - 1])
    {
        print(i - 1, j - 1);
        cout << s1[i - 1];
    }
    else
    {
        board[i - 1][j] > board[i][j - 1] ? print(i - 1, j) : print(i, j - 1);
    }
}

int main()
{

    cin >> s1 >> s2;

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                board[i][j] = board[i - 1][j - 1] + 1;
            }
            else
            {
                board[i][j] = max(board[i][j - 1], board[i - 1][j]);
            }
        }
    }
    cout << board[s1.size()][s2.size()] << "\n";
    print(s1.size(), s2.size());
}