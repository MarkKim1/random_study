#include <iostream>

using namespace std;
int f[41];
int fib1(int n,int count1){
    if(n == 1 || n == 2) return 1;
    return fib1(n-1,count1+1) + fib1(n-2,count1+1);
    const int n1 = 100;
    const int m1 = 100;
    int *arr = new int[n1][m1];
}

int fib2(int n, int count2){
    f[0] = 1;
    f[1] = 1;
    for(int i = 3; i < n; i++){
        f[i] = f[n-1] + f[n-2];
        count2++;
    }
    return count2;
}

int main () {
    int n;
    int count1 = 0;
    int count2 = 1;
    cin >> n;
    int a = fib1(n,count1);
    cout << a << " ";
    int b = fib2(n,count2);
    cout << b;
}