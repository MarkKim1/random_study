#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string combination = "";

string bestSum(int targetNum,vector<int>& numbers){
    if(targetNum == 0) return "";
    if(targetNum < 0) return "-1";

    string shorestCombination = "";

    for(int i = 0; i <numbers.size(); i++){
        int remainder = targetNum-numbers[i];
        string remainderCombination = bestSum(remainder,numbers);
        if(remainderCombination != "-1"){
            combination +=to_string(numbers[i]);
            if(shorestCombination == "" || combination.size() < shorestCombination.size()){
                shorestCombination = combination;
            }
        }
    }
    return shorestCombination;

}

int main () {
vector<int> numbers;
for(int i  = 0; i < 3; i++){
    numbers.push_back(i+1);
}
unordered_map<int,bool> memo;
string result = bestSum(8,numbers);
cout << result;
}