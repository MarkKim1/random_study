#include<iostream>
#include <cmath>

using namespace std;
bool IsPalindromeNumber(int x){
    if(x <= 0){
        return x == 0;
    }
    const int num_digits = static_cast<int>(floor(log10(x))) + 1;
    //cout << num_digits;
    int msd_mask = static_cast<int>(pow(10,num_digits-1));
    for(int i = 0; i < (num_digits / 2); i++){
        if(x/msd_mask != x%10){
            return false;
        }
        x %= msd_mask; //x의 최상위 숫자를 삭제한다.
        x /= 10; // x의 최하위 숫자를 삭제한다.
        msd_mask /= 100;
    }
    return true;
}

int main () {
    bool result;
    int x;
    cin >> x;
    result = IsPalindromeNumber(x);
    cout << boolalpha;
    cout << result << endl;
    return 0;
}