#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> ans;
vector<int> pi;
void get_pi(string P)
{
    int j = 0;
    for (int i = 1; i < P.size(); i++)
    {
        while (j > 0 and P[i] != P[j])
        {
            j = pi[j - 1];
        }
        if (P[i] == P[j])
        {
            pi[i] = ++j;
        }
    }
}

void kmp(string T, string P)
{
    get_pi(P);
    int j = 0;
    for (int i = 0; i < T.size(); i++)
    {
        while (j > 0 and T[i] != P[j])
        {
            j = pi[j - 1];
        }
        if (T[i] == P[j])
        {
            if (j == (int)P.size() - 1)
            {
                ans.push_back(i - P.size() + 1);
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{
    string T, P;
    getline(cin, T);
    getline(cin, P);
    pi.resize(P.size());
    kmp(T, P);
    cout << (int)ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] + 1 << "\n";
    }
}
