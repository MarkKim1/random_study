#include <iostream>
#include <vector>

using namespace std;
vector<vector<double>> vec;
double solve(double a, double b)
{
    double x1 = vec[0][0], y1 = vec[0][1];
    double x2 = vec[a][0], y2 = vec[a][1];
    double x3 = vec[b][0], y3 = vec[b][1];
    double temp = (x1 * y2 + x2 * y3 + x3 * y1);
    temp -= (x2 * y1 + x3 * y2 + x1 * y3);
    return temp / 2;
}

int main()
{
    int N;
    cin >> N;
    double result = 0;
    vec.resize(N, vector<double>(2));
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i][0] >> vec[i][1];
    }
    for (int i = 1; i < N - 1; i++)
    {
        result += solve(i, i + 1);
    }
    printf("%.1lf\n", abs(result));
}