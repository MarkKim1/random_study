#include <iostream>
#include <vector>
#define endl "\n"
#define MAX 4
using namespace std;
struct FISH
{
    int x, y, Dir;
    bool live;
};

int ans = 0;
int map[MAX][MAX];
FISH fish[20];

void move_fish()
{
}

void copy(int a[][4], FISH b[], int c[][4], FISH d[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            a[i][j] = c[i][j];
        }
    }
    for (int i = 0; i < 20; i++)
    {
        b[i] = d[i];
    }
}

// 1. 맵 과 물고기 정보를 카피한다.
// 2. 물고기를 이동시킨다
// 3. 상어를 이동시킨다.
// 4. 백트랙킹을 통해 상어가 잡아먹을수 있는 최대값을 찾는다
void solve(int i, int j, int dir, int curr_num)
{
    int C_MAP[MAX][MAX];
    FISH C_FISH[20];
    copy(C_MAP, C_FISH, map, fish);
    move_fish();
}

void input()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a, b;
            cin >> a >> b;
            map[i][j] = a;
            fish[a] = {i, j, b, true};
        }
    }
}

int main()
{
    input();
    // 초기 세팅 상어가 (0,0)dp 있는 물고기를 잡아먹는다
    int num = map[0][0];
    fish[num].live = false;
    map[0][0] = -1;
    int dir = fish[num].Dir;
    solve(0, 0, dir, num);
    cout << ans << endl;
}