#include<iostream>
#include<cmath>

using namespace std;

long long Reverse(int x){
    long long result = 0;
    while(x){
        //x가 음수이면, x%10은 최하위 숫자의 음수 값과 같다.
        //예를 들어 -256 % 10은 -6
        result = (result * 10) + (x %10);
        x /= 10;
    }
        return result;
}

int main () {

    int x = 0;
    cin >> x;
    long long result = Reverse(x);
    cout << result << endl;
    return 0;
}