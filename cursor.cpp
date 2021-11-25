#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    int count = 0,cur = 0;
    string str;
    char type,a;
    cin >> str;
    cur = str.size();
    cin >> count;
    for(int i = 1; i <= count; i++){
        cin >> type;
        if(type == 'L'){
            while(cur > 0){ 
                cur -= 1;
                break;
            }
                cout << str << endl;
        }
        else if(type == 'D'){
            while(cur < str.size()){
                cur+= 1;
                break;
            }
            cout << str << endl;
        }
        else if(type == 'B'){
            while(cur > 0){
                str.erase(str.begin()+cur-1);
                cur -= 1;
                break;
            }
            cout << str << endl;
        }
        else if(type == 'P'){
            cin >> a;
            str.insert(cur,1,a);
            cur++;
            cout << str << endl;
        }
    }
    cout << str << endl;
    //cur = str.size();
}