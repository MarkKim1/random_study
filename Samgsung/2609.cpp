#include <iostream>
using namespace std;

int get_gcd(int a, int b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while (b != 0)
    {
        int rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

int main()
{
    int A, B;
    cin >> A >> B;
    int gcd = get_gcd(A, B);
    int lcm = (A * B) / (gcd);
    cout << gcd << endl;
    cout << lcm << endl;
}