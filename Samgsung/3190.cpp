// 백준 뱀
// https://www.acmicpc.net/problem/3190

#include <iostream>
#include <vector>
#include <deque>

using namespace std;
vector<vector<int>> board;
int T;
int K;
int L;

int main()
{
    cin >> T;

    board.resize(T, vector<int>(T, 0));
    vector<pair<int, char>> V;
    vector<int> dy = {0, 1, 0, -1};
    vector<int> dx = {1, 0, -1, 0};

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int row, col;
        cin >> row >> col;
        board[row - 1][col - 1] = 2; // position for fruits;
    }
    cin >> L;

    for (int i = 0; i < L; i++)
    {
        int moves;
        char dir;
        cin >> moves >> dir;
        V.push_back({moves, dir});
    }
    int time = 0;
    int dir = 0;
    int x = 0;
    int y = 0;
    int indx = 0;
    deque<pair<int, int>> snake_body;
    snake_body.push_back({0, 0});
    while (1)
    {

        time++;
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (min(ny, nx) < 0 || ny >= T || nx >= T || board[ny][nx] == 1)
        {
            break;
        }
        else if (board[ny][nx] == 0)
        {
            board[snake_body.back().first][snake_body.back().second] = 0;
            snake_body.pop_back();
        }
        board[ny][nx] = 1;
        snake_body.push_front(make_pair(ny, nx));
        if (time == V[indx].first)
        {
            if (V[indx].second == 'D')
            {
                dir = (dir + 1) % 4;
            }
            else
            {
                dir = (dir + 3) % 4;
            }
            indx++;
        }
        y = ny;
        x = nx;
    }
    cout << time << endl;
    return 0;
}