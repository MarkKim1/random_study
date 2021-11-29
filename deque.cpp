#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

int main () {
    int testCase, member;
    string command;
    deque<int>dq;
    vector<int>vec;
    cin >> testCase;

    for(int i = 0; i < testCase; i++){
        cin >> command;
        if(command == "push_back"){
            cin >> member;
            dq.push_back(member);
        }
        else if(command == "push_front"){
            cin >> member;
            dq.push_front(member);
        }
        else if(command == "pop_front"){
            if(!dq.empty()){
                vec.push_back(dq.front());
                dq.pop_front();
            }
            else{
                vec.push_back(-1);
            }
        }
        else if(command == "pop_back"){
            if(!dq.empty()){
                vec.push_back(dq.back());
                dq.pop_back();
            }
            else{
                vec.push_back(-1);
            }
        }
        else if(command == "size"){
            vec.push_back(dq.size());
        }
        else if(command == "empty"){
            if(dq.empty()){
                vec.push_back(1);
            }
            else{
                vec.push_back(0);
            }
        }
        else if(command == "front"){
            if(!dq.empty()){
                vec.push_back(dq.front());
            }
            else{
                vec.push_back(-1);
            }
        }
        else if(command == "back"){
            if(!dq.empty()){
                vec.push_back(dq.back());
            }
            else{
                vec.push_back(-1);
            }
        }


    }
    for(int i = 0; i < vec.size(); i++){
        cout << vec.at(i) << endl;
    }
    return 0;
}