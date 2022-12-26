#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

int main (){
    unordered_map<int,list<pair<int,int>>> map;
    list<pair<int,int> > l;
    l.push_front(make_pair(1,2));
    l.push_front(make_pair(3,7));
    l.push_front(make_pair(5,6));
    map[3].push_back(make_pair(3,4));
    while(!l.empty()){
        cout << l.front().first << " " << l.front().second << "|";
        l.pop_front();
    }
    cout << endl;
    l.push_front(make_pair(1,2));
    l.push_front(make_pair(3,7));
    l.push_front(make_pair(5,6));
    map[3].push_back(make_pair(3,4));
    l.splice(l.begin(),l,map[3].begin());
    while(!l.empty()){
        cout << l.front().first << " " << l.front().second << "|";
        l.pop_front();
    }
}