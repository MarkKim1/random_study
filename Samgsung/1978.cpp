// 소수 찾기
// https://www.acmicpc.net/problem/1978

#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    int not_prime = 0;
    for (int i = 0; i < T; i++)
    {
        int A;
        cin >> A;
        if (A == 1)
        {
            not_prime++;
            continue;
        }
        for (int i = 2; i <= A; i++)
        {
            if (i == A)
            {
                break;
            }
            if (A % i == 0)
            {
                not_prime++;
                break;
            }
        }
    }
    cout << T - not_prime << endl;
}