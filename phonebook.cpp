#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main (){
   vector<string> phonebook;
   string num;
   string list;
   bool answer = true;
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
   sort(phonebook.begin(),phonebook.end());
   for(int i = 0; i < phonebook.size()-1; i++){
      if(phonebook.at(i) == phonebook.at(i+1).substr(0,phonebook.at(i).size())){
         answer = false;
         break;
      }
   }       
   cout << boolalpha;
   cout << answer<<endl;
   return 0; 
}