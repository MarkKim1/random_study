    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    string ifempty(string new_id){
        if(new_id == ""){
            for(int i = 0; i < 3; i++){
                new_id+='a';
            }
        }
        return new_id;
    }

    string solution(string new_id) {
        string answer = "";
        new_id = ifempty(new_id);
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
        answer = ifempty(answer);
        //step 4
        if(answer[0] == '.'){
            answer.erase(answer.begin());
        }
        int size = answer.size()-1;
        if(answer[size] == '.'){
            answer.erase(answer.end()-1);
        }
        answer = ifempty(answer);
        //step5
        if(answer.size() > 15){
            answer.erase(15, answer.length());
        }
        answer = ifempty(answer);

        if(answer[0] == '.'){
            answer.erase(answer.begin());
        }
        size = answer.size()-1;
        if(answer[size] == '.'){
            answer.erase(answer.end()-1);
        }

        if(answer.size() < 3)
        while(answer.size() < 3){
            answer+=answer.back();
        }



    cout << answer << endl;
        return answer;
    }


int main () {
    string new_id;
    cin >> new_id;
    solution(new_id);
}