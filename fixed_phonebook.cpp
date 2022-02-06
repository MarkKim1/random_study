#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main (){
    vector<string> phonebook;
    string list;
    string num;
    
getline(cin,list);
   for(int i= 0; i < list.size();i++){
      if(isnumber(list.at(i))){
         num+=list.at(i);
      }
      else if(list.at(i) == ']'){
         phonebook.push_back(num);
         num.erase();
      }
      else if(list.at(i) == ','){
         phonebook.push_back(num);
         num.erase();
      }
   }
}