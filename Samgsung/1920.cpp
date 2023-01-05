// 수 찾기
// https://www.acmicpc.net/problem/1920
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int A[100001];
int N, M;

void solve(int target)
{
    int left = 0;
    int right = N - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target == A[mid])
        {
            cout << 1 << "\n";
            return;
        }
        else if (target > A[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << 0 << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        A[i] = temp;
    }
    sort(A, A + N);
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        solve(temp);
    }
}