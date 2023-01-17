#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> vec(T + 1);
    vec[1] = 1;
    vec[2] = 2;
    for (int i = 3; i <= T; i++)
    {
        vec[i] = vec[i - 1] + vec[i - 2];
        vec[i] %= 10007;
    }
    cout << vec[T] << "\n";
}