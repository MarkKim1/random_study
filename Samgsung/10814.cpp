#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<pair<int, pair<int, string>>> vec;
    int age;
    string name;
    for (int i = 0; i < T; i++)
    {
        cin >> age >> name;
        vec.push_back({i, {age, name}});
    }
    sort(vec.begin(), vec.end(), [](pair<int, pair<int, string>> a, pair<int, pair<int, string>> b)
         {
        if(a.second.first == b.second.first){
            return a.first < b.first;
        }
        return a.second.first < b.second.first; });
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].second.first << " " << vec[i].second.second << "\n";
    }
    return 0;
}