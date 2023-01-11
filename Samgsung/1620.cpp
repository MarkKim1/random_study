#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    map<string, string> map1;
    map<string, string> map2;
    for (int i = 1; i <= N; i++)
    {
        string A;
        cin >> A;
        map1[to_string(i)] = A;
        map2[A] = to_string(i);
    }
    for (int i = 0; i < M; i++)
    {
        string A;
        cin >> A;
        if (isdigit(A[0]))
        {
            cout << map1[A] << "\n";
        }
        else
        {
            cout << map2[A] << "\n";
        }
    }
}