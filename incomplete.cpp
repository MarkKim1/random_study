#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    vector<string> participant;
    vector<string> completion;
    string name;
    string alpha;
    string solution="";

    getline(cin,name);
    for(int i = 0; i < name.size(); i++){
        if(isalpha(name.at(i))){
            alpha+=name.at(i);
        }
        else if(name.at(i) == ']'){
            participant.push_back(alpha);
            alpha.erase();
        }
        else if(name.at(i) == ','){
            participant.push_back(alpha);
            alpha.erase();
        }

    }
    getline(cin,name);
    for(int i = 0; i < name.size(); i++){
        if(isalpha(name.at(i))){
            alpha+=name.at(i);
        }
        else if(name.at(i) == ']'){
            completion.push_back(alpha);
            alpha.erase();
        }
        else if(name.at(i) == ','){
            completion.push_back(alpha);
            alpha.erase();
        }
    }

    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    for(int i = 0; i < completion.size(); i++){
        if(participant.at(i) != completion.at(i)){
            solution = participant.at(i);
        }
    }
    solution = participant[participant.size()-1];
    cout << solution << endl;
    // for(int i = 0; i < participant.size(); i++){
    //     cout << participant.at(i);
    // }
    // for(int i = 0; i < completion.size(); i++){
    //     cout << completion.at(i);
    // }

    return 0;
}