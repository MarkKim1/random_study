#include <iostream>

using namespace std;

class Person{
    public:
        string name_;
        int age_;
    
    void person(string &name, int age){
        name_ = name;
        age_ = age;
    }

    void showpersoninfo(){
        cout << name_ <<"'s age is " << age_ << endl;
    }

};

class otherPerson: public Person{
    public:
        void ability(){
            if(age_ > 10){
                cout << "he is strong" << endl;
            }
        }

};



int main (){
    Person person;
    otherPerson person_;
    string name = "Minseok";
    int age = 26;
    person.person(name,age);
    person.showpersoninfo();
    person_.ability();
    

}