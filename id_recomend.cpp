#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    if(new_id == ""){
        new_id +='a';
    }
    //step 1
    for(int i = 0; i < new_id.size(); i++){
        if(isalpha(new_id[i])){
            new_id[i] = tolower(new_id[i]);
        }
    }
    //step2, step3 
    char temp = '\0';
    for(int i = 0; i < new_id.size(); i++){
        if(isalpha(new_id[i]) || isdigit(new_id[i]) || 
           new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
               if(temp == '.' && new_id[i] == '.')
               continue;
               
               answer+=new_id[i];
           }
           temp = new_id[i];
    }
    //step5
    

    //step 4
    if(answer[0] == '.'){
        answer.erase(answer.begin() + 0);
    }
    int size = answer.size()-1;
    if(answer[size] == '.'){
        answer.erase(answer.begin() + size);
    }


cout << answer << endl<<endl;
    return answer;
}


int main () {
    string new_id;
    cin >> new_id;
    solution(new_id);
}