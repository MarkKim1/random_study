#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main () {

int testCase,element;
string command;
queue<int> str;
vector<int> vec;
cin >> testCase;

    for(int i = 0; i < testCase; i++){
        cin >> command;
        if(command == "push"){
            cin >> element;
            str.push(element);
        }
        else if(command == "pop"){
            if(str.empty()){
                vec.push_back(-1);
            }
            else{
                vec.push_back(str.front());
                str.pop();
            }
        }
        else if(command == "size"){
            vec.push_back(str.size());
        }
        else if(command == "empty"){
            if(!str.empty()){
                vec.push_back(0);
            }
            else{
                vec.push_back(1);
            }
        }
        else if(command == "front"){
            if(!str.empty()){
                vec.push_back(str.front());
            }
            else{
                vec.push_back(-1);
            }
        }
        else if(command == "back"){
            if(str.empty()){
                vec.push_back(-1);
            }
            else{
                vec.push_back(str.back());
            }
        }
    }
    for(int i = 0; i < vec.size(); i++){
        cout << vec.at(i) << endl;
    }

}