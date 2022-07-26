#include <iostream>
#include <algorithm>
using namespace std;
int W[100],V[100];
int N,K;
int dp[101][100001] = {0};
int go(int i, int w){
    if(dp[i][w] > 0) return dp[i][w];
    if(i == N) return 0;
    int n1 = 0;
    if(w+W[i] <= K){
        n1 = V[i] + go(i+1,w+W[i]);
    }
    int n2 = go(i+1,w);
    return dp[i][w] = max(n1,n2);
}


int main () {
    cin >>N >> K;
    for(int i = 0; i < N; i++){
        cin >> W[i] >> V[i];
    }
    cout << go(0,0);
}

