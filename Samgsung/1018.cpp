// 체스판 다시 칠하기
// https://www.acmicpc.net/problem/1018
#include <iostream>
#include <string>
#include <limits.h>
#include <vector>
using namespace std;
string BW[8] = {
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"}};
string WB[8] = {
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"}};
vector<vector<char>> board;

int comp(int x, int y)
{
    int BW_count = 0;
    int WB_count = 0;

    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if (board[i][j] != BW[i - x][j - y])
            {
                BW_count++;
            }
            if (board[i][j] != WB[i - x][j - y])
            {
                WB_count++;
            }
        }
    }
    return min(BW_count, WB_count);
}
int main()
{
    int A, B;
    cin >> A >> B;
    board.resize(A, vector<char>(B));
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < B; j++)
        {
            cin >> board[i][j];
        }
    }
    int result = INT_MAX;
    for (int i = 0; i <= A - 8; i++)
    {
        for (int j = 0; j <= B - 8; j++)
        {
            result = min(comp(i, j), result);
        }
    }
    cout << result << endl;
    return 0;
}
