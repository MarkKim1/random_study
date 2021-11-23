#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main () {
    int testcase;
    cin >> testcase;
    cin.ignore();

    while (testcase--){
        string str;
        getline(cin, str);
        str+='\n';
        stack<char> stk;
        for(char ch : str){
            if(ch == ' ' || ch == '\n'){
                while(!stk.empty()){
                    cout << stk.top();
                    stk.pop();
                }
                cout << ch;
            }
            else {
                stk.push(ch);
            }
        }
    }
}