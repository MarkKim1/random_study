#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main () {
    int n,amx;
    int cnt = 0;
    int seq[100001];
    vector<int> v;
    vector<char> ans;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }
    for(int i = 1; i <= n; i++){
        v.push_back(i);
        ans.push_back('+');
    

        while(!v.empty() && v.back() == seq[cnt]){
            v.pop_back();
            ans.push_back('-');
            cnt++;
        }
    }
    if(!v.empty()){
        cout << "NO" << endl;
    }
    else{
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << endl;
        }
    }

}