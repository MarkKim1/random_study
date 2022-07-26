//아래와 같은 문자열 클래스를 완성해보세요

#include <iostream>
//#include<string.h>

class string {
    char *str;
    int len;

    public:
    string(char c, int n);
    string(const char *s);
    string(const string &s);
    ~string();

    void add_string(const string &s);
    void copy_string(const string &s);
    void print();
    int strlen();
};

string::string(char c, int n){
    str = new char[n+1];
    for(int i = 0; i < n; i++){
        str[i] = c;
    }
    len = n;
}
string::string(const char* s){
    len = ::strlen(s) + 1;
    str = new char[::strlen(s) + 1];
    for(int i = 0; i < len; i++){
        str[i] = s[i];
    }
    
}

string::string(const string &s){
    len = s.len;
    str = new char[::strlen(s.str) + 1];
    for(int i = 0; i < len; i++){
        str[i] = s.str[i];
    }
    
}
string::~string(){
    std::cout <<"소멸자 생성! " <<std::endl;
    if(str != NULL){
        delete[] str;
    }
}
void string::add_string(const string &s){
    len = s.len + len;
    char *temp = new char[len+1];
    strcat(temp,str);
    strcat(temp,s.str);
    delete[] str;
    str = new char[len + 1];
    strcpy(str,temp);
    delete[] temp;
}


void string::copy_string(const string &s){
    int newlen = s.len;
    delete[] str;
    str = new char[newlen + 1];
    for(int i = 0; i < newlen; i++){
        str[i] = s.str[i];
    }
}
void string::print(){
    std::cout << str <<std::endl;
}
int string::strlen(){
    std::cout << len <<std::endl;
    return len;
}



int main () {
    string a('c',5);
    a.strlen();
    string l(a);
    l.print();
    l.strlen();

    string b("hello");
    //b.print();
    string d("this is copy of string");
    //d.print();
    b.add_string(d);
    b.print();
    a.add_string(b);
    a.print();
    a.copy_string(d);
    a.print();

}