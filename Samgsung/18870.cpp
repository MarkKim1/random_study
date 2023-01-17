#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> original(T);
    vector<int> sorted(T);
    unordered_map<int, int> map;
    int curr = 0;
    for (int i = 0; i < T; i++)
    {
        cin >> original[i];
        sorted[i] = original[i];
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < sorted.size(); i++)
    {
        if (map.find(sorted[i]) == map.end())
        {
            map[sorted[i]] = curr;
            curr++;
        }
    }
    for (int i = 0; i < original.size(); i++)
    {
        cout << map[original[i]] << " ";
    }
}