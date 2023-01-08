#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    while (cin >> A >> B >> C)
    {
        if (A == 0 and B == 0 and C == 0)
        {
            break;
        }
        if (A > B)
        {
            int temp = A;
            A = B;
            B = temp;
        }
        if (B > C)
        {
            int temp = B;
            B = C;
            C = temp;
        }
        if (C * C == A * A + B * B)
        {
            cout << "right" << endl;
        }
        else
        {
            cout << "wrong" << endl;
        }
    }
}