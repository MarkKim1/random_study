#include<iostream>

using namespace std;

double Power(double x, int y){
    double result = 1.0;
    long long power = y;
    int count = 0;
    if(y<0){
        power = -power;
        x = 1.0/x;
    }
    while(power != 0){
        if((power&1) != 0){
            result *= x;
            
        }
        x *= x, power >>= 1;
        //cout << x << endl;
    }
   
    return result;
}

int main () {
    double x = 1.1;
    int y = 4;
    double result = Power(x,y);
    cout << result << endl;
}