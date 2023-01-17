#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> vec;
    for (int i = 0; i < T; i++)
    {
        int A;
        cin >> A;
        vec.push_back(A);
    }
    sort(vec.begin(), vec.end());
    int result = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        vec[i] = vec[i - 1] + vec[i];
        result += vec[i];
    }
    cout << result << "\n";
}