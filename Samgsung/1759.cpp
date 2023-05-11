#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;
unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
vector<string> result;
int L, C;

void solve(vector<char> &list, string curr, int index)
{
    if (curr.size() == L)
    {
        bool finished = false;
        int consonant_count = 0;
        for (int i = 0; i < curr.size(); i++)
        {
            if (vowel.count(curr[i]))
            {
                finished = true;
            }
            if (!vowel.count(curr[i]))
            {
                consonant_count++;
            }
        }
        if (finished and consonant_count >= 2)
        {
            result.push_back(curr);
        }
        return;
    }

    for (int i = index; i < list.size(); i++)
    {
        curr.push_back(list[i]);
        solve(list, curr, i + 1);
        curr.pop_back();
    }
}

int main()
{

    cin >> L >> C;
    vector<char> list(C);
    for (int i = 0; i < C; i++)
    {
        cin >> list[i];
    }
    sort(list.begin(), list.end());
    solve(list, "", 0);
    for (string each : result)
    {
        cout << each << "\n";
    }
}