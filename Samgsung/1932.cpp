#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int count = 1;
    vector<vector<long long>> board;
    for (int i = 0; i < T; i++)
    {
        vector<long long> temp;
        for (int i = 0; i < count; i++)
        {
            int A;
            cin >> A;
            temp.push_back(A);
        }
        board.push_back(temp);
        count++;
    }
    for (int i = board.size() - 1; i >= 1; i--)
    {
        for (int j = 0; j < board[i].size() - 1; j++)
        {
            board[i - 1][j] += max(board[i][j], board[i][j + 1]);
        }
    }
    cout << board[0][0] << endl;
}
