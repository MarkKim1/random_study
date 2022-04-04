#include<iostream>
#include<cmath>

using namespace std;

unsigned long long ReverseBits(unsigned long long x) {
    const int kMaskSize = 16;
    const int kBitMask = 0xFFFF;
    //cout << kBitMask << endl;
    return precomputed_reverse[x & kBitMask] << (3 * kMaskSize) |
           precomputed_reverse[(x >> kMaskSize) & kBitMask] <<(2*kMaskSize) ||
           precomputed_reverse[(x >>(2 * kMaskSize)) & kBitMask] << kMaskSize |
           precomputed_reverse[(x >> (3*kMaskSize)) & kBitMask];
}

int main () {
    unsigned long long a = 10;
    //cout << ReverseBits(a);

}