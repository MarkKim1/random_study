#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct location
{
    int x, y, z, count;
};

int main()
{
    int M, N, H;
    queue<location> q;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    cin >> M >> N >> H;
    int box_size = M * N * H;
    int curr_tomato_count = 0;
    int box[101][101][101];

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                {
                    q.push({i, j, k, 0});
                    curr_tomato_count++;
                }
                else if (box[i][j][k] == -1)
                {
                    box_size--;
                }
            }
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        location curr = q.front();
        q.pop();
        int curr_H = curr.x;
        int curr_N = curr.y;
        int curr_M = curr.z;
        int curr_count = curr.count;
        ans = curr_count;
        for (int i = 0; i < 4; i++)
        {
            int new_N = curr_N + dx[i];
            int new_M = curr_M + dy[i];
            if (min(new_N, new_M) >= 0 and new_N < N and new_M < M and box[curr_H][new_N][new_M] == 0)
            {
                box[curr_H][new_N][new_M] = 1;
                curr_tomato_count++;
                q.push({curr_H, new_N, new_M, curr_count + 1});
            }
        }
        if (curr_H + 1 < H and box[curr_H + 1][curr_N][curr_M] == 0)
        {
            box[curr_H + 1][curr_N][curr_M] = 1;
            curr_tomato_count++;
            q.push({curr_H + 1, curr_N, curr_M, curr_count + 1});
        }
        if (curr_H - 1 >= 0 and box[curr_H - 1][curr_N][curr_M] == 0)
        {
            box[curr_H - 1][curr_N][curr_M] = 1;
            curr_tomato_count++;
            q.push({curr_H - 1, curr_N, curr_M, curr_count + 1});
        }
    }
    if (curr_tomato_count == box_size)
    {
        cout << ans << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
}