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
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "\n";
    }
}