#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

int main () {
    short x = 10;
    short result = 0;
    result ^=(x & 1);
    bitset<16> n(result);
    cout << n << endl;

}