#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, int> map;
vector<int> vec;
int N, S;
long long ans = 0;
void left(int index, int curr)
{
    if (index == N / 2)
    {
        map[curr]++;
        return;
    }
    left(index + 1, curr);
    left(index + 1, curr + vec[index]);
}

void right(int index, int curr)
{
    if (index == N)
    {
        ans += map[S - curr];
        return;
    }
    right(index + 1, curr);
    right(index + 1, curr + vec[index]);
}

int main()
{

    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        vec.push_back(A);
    }
    int mid = vec.size() / 2;
    left(0, 0);
    right(N / 2, 0);
    if (!S)
        ans--;
    cout << ans << "\n";
}