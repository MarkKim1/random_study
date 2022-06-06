#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string combination = "";

string bestSum(int targetNum,vector<int>& numbers,unordered_map<int,string> memo){
    if(memo.find(targetNum) != memo.end()) return memo[targetNum];
    if(targetNum == 0) return "";
    if(targetNum < 0) return "-1";

    string shorestCombination = "";

    for(int i = 0; i <numbers.size(); i++){
        int remainder = targetNum-numbers[i];
        string remainderCombination = bestSum(remainder,numbers,memo);
        if(remainderCombination != "-1"){
            combination +=to_string(numbers[i]);
            if(shorestCombination == "" || combination.size() < shorestCombination.size()){
                shorestCombination = combination;
            }
        }
    }
    memo[targetNum] = shorestCombination;
    return shorestCombination; 

}

int main () {
vector<int> numbers = {2,3,5};
unordered_map<int,string> memo;
string result = bestSum(8,numbers,memo);
cout << result << endl;
result = bestSum(10,numbers,memo);
cout << result << endl;
}