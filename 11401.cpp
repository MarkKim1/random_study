#include <iostream>
using namespace std;
int N,K;
long long n;
    long long k;
    long long nMinusK = 1;
    long long mod = 1000000007;
    long long half;
long long solve(int x){
    if(x == 0) return 1;
    if(x % 2 == 1) return k * solve(x-1) % mod;
    else{
        half = solve(x/2);
        return half * half % mod;
    }
}

int main (){
    
    cin >> N >> K;
    n = 1;
    for(int i = N; i >= N-K+1; --i){
        n=(n*i) % mod;
    }
    k = 1;
    for(int i = 1; i <=K; i++){
        k=(k*i) % mod;
    }
    k = solve(mod-2);
    cout << n * k % mod;
}
