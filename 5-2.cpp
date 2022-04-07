#include<iostream>
#include<vector>
using namespace std;

vector<int> PlusOne(vector<int>A){
    ++A.back();
    for(int i = A.size() - 1; i > 0 && A[i] == 10; --i){
        A[i] = 0,++A[i-1];
    }
    return A;
}

int main () {
    vector<int> a;
    int b;
    int number;
    cout << "how many numbers: ";
    cin >> b;
    for(int i =0; i < b; i++){
        cin>>number;
        a.push_back(number);
    }

    a = PlusOne(a);
    for(int i = 0; i < a.size(); i++){
        cout << a.at(i) << endl;
    }
}