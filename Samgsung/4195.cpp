#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> map;
unordered_map<string, int> Cnt;

string Find(string a)
{
    if (map[a] == a)
    {
        return a;
    }
    else
    {
        return map[a] = Find(map[a]);
    }
}

void Union(string a, string b)
{

    string A = Find(a);
    string B = Find(b);
    if (A == B)
        return;
    map[B] = A;
    Cnt[A] += Cnt[B];
}
int main(int argc, char **argv)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        map.clear();
        Cnt.clear();
        int F;
        cin >> F;
        for (int i = 0; i < F; i++)
        {
            string a, b;
            cin >> a >> b;
            if (map[a].empty())
            {
                map[a] = a;
                Cnt[a] = 1;
            }
            if (map[b].empty())
            {
                map[b] = b;
                Cnt[b] = 1;
            }
            Union(a, b);
            cout << Cnt[Find(a)] << "\n";
        }
    }
}