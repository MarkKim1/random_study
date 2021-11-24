// 백준 9012번 괄호
#include <iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

bool Check(string str){
    int len = (int)str.length();
    stack<char> st;

    for(int i = 0; i < len; i++){
        char c = str[i];
        if(c == '('){
            st.push(str[i]);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else{
                return false;
            }
            
        }
    }
    return st.empty();
}

int main () {
    int testCase;
    string str;
    vector<string> stk;
    cin >> testCase;
    for(int i = 0; i < testCase; i++){
        cin >> str;
        if(Check(str)){
            stk.push_back("YES");
        }
        else{
            stk.push_back("NO");
        }
    }
    for(int i = 0; i < testCase; i++){
        cout << stk.at(i) << endl;
    }
}