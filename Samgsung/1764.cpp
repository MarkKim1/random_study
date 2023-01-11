#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    unordered_set<string> set;
    vector<string> vec;
    for (int i = 0; i < N + M; i++)
    {
        string A;
        cin >> A;
        if (set.count(A))
        {
            vec.push_back(A);
        }
        else
        {
            set.insert(A);
        }
    }
    sort(vec.begin(), vec.end());
    cout << vec.size() << "\n";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "\n";
    }
}
