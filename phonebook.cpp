#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main (){
   vector<string> phonebook;
   string num;
   string list;
   int number = 0;
   int count = 0;
   int vector = 1;
   int flag = -1;
   int other_flag = 0;
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
   number = stoi(phonebook.at(0));
   while(number > 1){
      number /=10;
      count++;
   }
   int other_count = count;
   int other_vector = 0;
   while(true){
      if(phonebook[other_vector++][other_count] == phonebook[0][other_count]){
         if(phonebook[other_vector][other_count] == phonebook[0][other_count]){
         flag++;
         other_count--;
            if(flag == count){
               cout << "false" << endl;
               break;
               flag = 1;
            }
         }
      }
   }
   if(flag == 0){
         cout << true << endl;

   }                   
   return 0; 
}