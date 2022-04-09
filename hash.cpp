#include <iostream>
#include <string>
using namespace std;
class MyHashSet {
    int arr[10000];
    int index;
    bool it_contains;
public:
    MyHashSet() {
    }
    
    void add(int key) {
        int index = key % 1024;
        cout << "index: "<< index << endl;
                arr[index] = key; 
                cout << arr[index] << endl;
            
    }
    
    void remove(int key) {
        int index = key % 1024;
        arr[index] = 0;
        
    }
    
    bool contains(int key) {
        int index = key % 1024;
        if(arr[index] == key){
           return true;
        }
        return false;
    }
};

int main (){
    MyHashSet* obj = new MyHashSet();
    string whatToDo;
    int number;
    while(true){
        cin >> whatToDo;
        if(whatToDo == "myhashset"){
            //MyHashSet* obj = new MyHashSet();
        }
        else if(whatToDo == "add"){
            cin >> number;
            obj->add(number);
        }
        else if(whatToDo == "contain"){
            cin >> number;
            bool param_3 = obj->contains(number);
            cout << boolalpha;
            cout << param_3 << endl;
        }
        else if(whatToDo == "remove"){
            cin >> number;
            obj -> remove(number);
        }
        else if(whatToDo == "qq"){
            break;
        }
    }
}