#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int lower(int *vec, int target)
{
    int left = 0;
    int right = N;
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (target <= vec[mid])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
int upper(int *vec, int target)
{
    int left = 0;
    int right = N;
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (vec[mid] > target)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    cin >> N;
    int vec1[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vec1[i]);
    }
    cin >> M;
    sort(vec1, vec1 + N);
    for (int i = 0; i < M; i++)
    {
        int A;
        scanf("%d", &A);
        int a = lower(vec1, A);
        int b = upper(vec1, A);
        cout << b - a << " ";
    }
}