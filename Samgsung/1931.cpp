// 끝나는 시간순으로 정렬을 해야 문제를 풀수있다

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> vec;
    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        vec.push_back(make_pair(end, start));
    }
    sort(vec.begin(), vec.end());
    
    // cout << endl;
    // for (auto a : vec)
    // {
    //     cout << a.first << " " << a.second << endl;
    // }
    auto curr = vec[0].first;
    int count = 1;
    for (int i = 1; i < vec.size(); i++)
    {
        if (curr <= vec[i].second)
        {
            count++;
            curr = vec[i].first;
        }
    }
    cout << count;
}