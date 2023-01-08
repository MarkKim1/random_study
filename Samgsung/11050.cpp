#include <iostream>
using namespace std;

int facto(int A)
{
    int result = 1;
    for (int i = 1; i <= A; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int A, B;
    cin >> A >> B;
    cout << facto(A) / (facto(B) * facto(A - B)) << endl;
}