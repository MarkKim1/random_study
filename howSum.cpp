#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    vector<int> numbers;
    vector<int> result;
    unordered_map<int,bool> memo; 
    
    Solution(vector<int> a){
        this->numbers = a;
    }
    
    bool howSum(int targetsum){    
        if(memo.find(targetsum) != memo.end()) return memo[targetsum];
        if(targetsum == 0) return true;
        if(targetsum < 0) return false;

        for(int num: numbers){
            int remainder = targetsum - num;
            if(howSum(remainder)){
                memo[targetsum] = true;
                this->result.push_back(num);
                return true;
            }
        }
        memo[targetsum] = false;
        return false;
    }
    
    void print(){
        if(result.empty()){
            cout << "null" << endl;
            return;
        }
        cout << '[';
        for(int i: result){
            cout << i << " ";
        }

        cout << ']';
        cout << endl;
    }


};

int main (){
    vector<int> arr = {2,3};
    Solution *a = new Solution(arr);
    a->howSum(7);
    a->print();

    arr = {5,3,4,7};
    Solution *b = new Solution(arr);
    b->howSum(7);
    b->print();

    arr = {2,4};
    Solution *c = new Solution(arr);
    c->howSum(7);
    c->print();

    arr = {2,3,5};
    Solution *d = new Solution(arr);
    d->howSum(8);
    d->print();
    
    arr = {7,14};
    Solution *e = new Solution(arr);
    e->howSum(300);
    e->print();

}