// https://www.acmicpc.net/problem/1007
// 벡터 매칭

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
double result = 1e9;

double sum(vector<pair<int, int>> vec, vector<bool> visited)
{
    pair<int, int> sub = {0, 0};
    for (int i = 0; i < vec.size(); i++)
    {
        if (visited[i])
        {
            sub.first -= vec[i].first;
            sub.second -= vec[i].second;
        }
        else
        {
            sub.first += vec[i].first;
            sub.second += vec[i].second;
        }
    }
    return sqrt(pow(sub.first, 2) + pow(sub.second, 2));
}

void solve(vector<pair<int, int>> vec, int index, int A, vector<bool> &visited, int cnt)
{
    if (cnt == A / 2)
    {
        result = min(result, sum(vec, visited));
    }
    for (int i = index; i < vec.size(); i++)
    {
        visited[i] = true;
        solve(vec, i + 1, A, visited, cnt + 1);
        visited[i] = false;
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        vector<pair<int, int>> vec(A);
        vector<bool> visited(A);
        for (int i = 0; i < A; i++)
        {
            cin >> vec[i].first >> vec[i].second;
        }
        solve(vec, 0, A, visited, 0);
        printf("%0.6lf\n", result);
        result = 1e9;
    }
}