#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool cansum(int targetsum, vector<int>& numbers, unordered_map<int,bool> memo){
    if(memo.find(targetsum) != memo.end()) return memo[targetsum];
    if(targetsum == 0) return true;
    if(targetsum < 0) return false;

    for(int num : numbers){
        int remainder = targetsum-num;
        if(cansum(remainder,numbers,memo)){
            memo[targetsum] = true;
            return true;
        }
    }
    memo[targetsum] = false;
    return false;
}

int main () {
    vector<int> numbers = {2,4};
    int targetsum = 8;
    unordered_map<int,bool> memo;
    bool a = cansum(targetsum,numbers,memo);
    cout <<boolalpha << a << endl;
}