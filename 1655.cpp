#include <iostream>
#include <queue>
using namespace std;
 int main () {
     ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int> > minheap;
    bool isOdd = true;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int res;
        cin >> res;
        if(isOdd){
            maxheap.push(res);
        }else{
            minheap.push(res);
        }

        if(!minheap.empty() and maxheap.top() > minheap.top()){
            int maxtop = maxheap.top();
            int mintop = minheap.top();
            maxheap.pop();
            minheap.pop();
            maxheap.push(mintop);
            minheap.push(maxtop);
        }
        isOdd = !isOdd;
        cout << maxheap.top() << '\n';
    }
    return 0;
 }