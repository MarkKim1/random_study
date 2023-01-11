#include <iostream>
#include <queue>
using namespace std;
int N, M;
bool visited[100001] = {false};
int path[100001] = {0};

bool isValid(int n)
{
    if (n < 0 || n > 100000 || visited[n])
    // n > 100000 인 이유는 n이 M보다 커질수 있기 때문이다.
    // 수빈이가 5-10-9-"18"-17 순으로 가면 4초만에 동생을 찾을 수 있다.
    // 그러므로 n > M은 틀린 연산이다.
    {
        return false;
    }
    return true;
}

int main()
{
    cin >> N >> M;
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = true;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if (curr.first == M)
        {
            cout << curr.second << endl;
            break;
        }
        if (isValid(curr.first + 1))
        {
            q.push(make_pair(curr.first + 1, curr.second + 1));
            visited[curr.first + 1] = true;
        }
        if (isValid(curr.first - 1))
        {
            q.push(make_pair(curr.first - 1, curr.second + 1));
            visited[curr.first - 1] = true;
        }
        if (isValid(curr.first * 2))
        {
            q.push(make_pair(curr.first * 2, curr.second + 1));
            visited[curr.first * 2] = true;
        }
    }
}