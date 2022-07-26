#include <iostream>
using namespace std;
int main () {
int n = 2;
bool dp[n][n];
fill_n(*dp,n*n,true);
int ans = 0;
for(int i = 0; i < n-1; i++){
    ans+=dp[i][i+1];
}
cout << ans;
return 0;
}