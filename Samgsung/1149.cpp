#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<vector<int>> rgb;
    for (int i = 0; i < T; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        rgb.push_back({A, B, C});
    }
    for (int i = 1; i < rgb.size(); i++)
    {
        rgb[i][0] += min(rgb[i - 1][1], rgb[i - 1][2]);
        rgb[i][1] += min(rgb[i - 1][0], rgb[i - 1][2]);
        rgb[i][2] += min(rgb[i - 1][0], rgb[i - 1][1]);
    }
    cout << min(rgb[T - 1][0], min(rgb[T - 1][1], rgb[T - 1][2])) << "\n";
}