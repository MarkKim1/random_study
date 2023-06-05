#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 111
char MAP[MAX][MAX];
bool VISIT[MAX][MAX];
bool KEY[26];
int h, w;
int ans = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

string first_key;

void setup()
{
    memset(MAP, 0, sizeof(MAP));
    memset(VISIT, false, sizeof(VISIT));
    memset(KEY, false, sizeof(KEY));
    first_key.clear();
    ans = 0;
}

void input()
{
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> MAP[i][j];
        }
    }
    cin >> first_key;
    for (int i = 0; i < first_key.size(); i++)
    {
        if (first_key[i] == '0')
            continue;
        KEY[first_key[i] - 'a'] = true;
    }
}

void BFS(int i, int j)
{
    queue<pair<int, int>> Q;
    queue<pair<int, int>> DOOR[26];
    VISIT[i][j] = true;
    Q.push(make_pair(i, j));

    while (!Q.empty())
    {
        auto curr = Q.front();
        int curr_i = curr.first;
        int curr_j = curr.second;
        Q.pop();
        for (int a = 0; a < 4; a++)
        {
            int nx = curr_i + dx[a];
            int ny = curr_j + dy[a];
            if (min(nx, ny) >= 0 and nx <= h + 1 and ny <= w + 1)
            {
                if (MAP[nx][ny] == '*' || VISIT[nx][ny] == true)
                {
                    continue;
                }
                VISIT[nx][ny] = true;
                if ('A' <= MAP[nx][ny] and MAP[nx][ny] <= 'Z')
                {
                    if (KEY[MAP[nx][ny] - 'A'] == true)
                    {
                        Q.push(make_pair(nx, ny));
                    }
                    else
                    {
                        DOOR[MAP[nx][ny] - 'A'].push(make_pair(nx, ny));
                    }
                }
                else if ('a' <= MAP[nx][ny] and MAP[nx][ny] <= 'z')
                {
                    Q.push(make_pair(nx, ny));
                    KEY[MAP[nx][ny] - 'a'] = true;
                    while (!DOOR[MAP[nx][ny] - 'a'].empty())
                    {
                        auto curr = DOOR[MAP[nx][ny] - 'a'].front();
                        Q.push(curr);
                        DOOR[MAP[nx][ny] - 'a'].pop();
                    }
                }
                else
                {
                    Q.push(make_pair(nx, ny));
                    if (MAP[nx][ny] == '$')
                    {
                        ans++;
                    }
                }
            }
        }
    }
}

int main()
{
    int Tc;
    cin >> Tc;
    for (int i = 0; i < Tc; i++)
    {
        setup();
        input();
        BFS(0, 0);
        cout << ans << "\n";
    }
}