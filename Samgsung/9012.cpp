#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    vector<string> result;
    for (int i = 0; i < T; i++)
    {
        string S;
        int curr = 0;
        cin >> S;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '(')
            {
                curr++;
            }
            else
            {
                curr--;
                if (curr < 0)
                {
                    break;
                }
            }
        }
        if (curr == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}