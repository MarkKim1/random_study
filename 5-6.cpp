#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main () {
    vector<int> a;
    int arrayNumber;
    int value;
    cout << "Array Number: ";
    cin >> arrayNumber;
    for(int i = 0; i < arrayNumber; i++){
        cin >>value;
        a.push_back(value);
    }
    const int MID = (a.size() / 2) -1;
    sort(a.begin(), a.begin()+MID,greater<int>());
    sort(a.begin()+MID+1, a.end(),greater<int>());

    for(int i = 0; i < a.size(); i++){
        cout << a.at(i) << endl;
    }
    int b = (a[+MID+1])-(a[MID]);

    cout << "RESULT: " << b <<endl;

    return 0;
}