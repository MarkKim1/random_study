#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    if (B.size() > A.size())
    {
        swap(A, B);
    }
    vector<vector<int>> board(B.size() + 1, vector<int>(A.size() + 1, 0));
    for (int i = 1; i < board.size(); i++)
    {
        for (int j = 1; j < board[i].size(); j++)
        {
            if (B[i - 1] == A[j - 1])
            {
                board[i][j] = board[i - 1][j - 1] + 1;
            }
            else
            {
                board[i][j] = max(board[i - 1][j], board[i][j - 1]);
            }
        }
    }
    cout << board[B.size()][A.size()] << endl;
}