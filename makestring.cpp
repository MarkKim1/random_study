#include <iostream>
 /*
 1. 문자로 부터의 문자열 생성, 문자열로 부터의 생성
 2. 문자열 길이를 구하는 함수
 3. 문자열 뒤에 다른 문자열 붙이기
 4. 문자열 내에 포함되어 있는 문자열 구하기
 5. 문자열이 같은지 비교
 6. 문자열 크기 비교
*/

class String{
    char char_content;
    char* string_content;
    int string_length;
    int memory_capacity;

    public:
    //문자로 부터의 문자열 생성 
    String(char c);
    String(const char* c);
    String(const String& c);
    ~String();

    String& assign(const String& c);
    String& assign(const char* c);
    int capacity() const;
    void reserve(int x);

    char at(int i) const;

    String& insert(int loc, const String& c);
    String& insert(int loc, const char* c);
    String& insert(int loc, char c);

    String& erase(int loc, int num);

    void add_string(const String& c); 
    void print();
};

String::String(char c){
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
    memory_capacity = 1;
}
String::String(const char* c){
    string_length = strlen(c);
    memory_capacity = string_length;
    string_content = new char[string_length];
    
    for(int i = 0; i < string_length; i++){
        string_content[i] = c[i];
    }
}
String::String(const String& c){
    string_length = c.string_length;
    string_content = new char[string_length];
    memory_capacity = c.string_length;
    for(int i = 0; i < string_length; i++){
        string_content[i] = c.string_content[i];
    }
}
String::~String(){
    std::cout << "소멸자" <<std::endl;
    if(string_content){
        delete[] string_content;
    }
}
String& String::assign(const String& c){
    if(c.string_length > memory_capacity){
        delete[] string_content;
        string_content = new char[c.string_length];
        memory_capacity = c.string_length;
    }
    for(int i = 0; i < string_length; i++){
        string_content[i] = c.string_content[i];
    }
    string_length = c.string_length;
    return *this;
}
String& String::assign(const char* c){
    int n = strlen(c);
    if(n > memory_capacity){
        delete[] string_content;
        string_content = new char[n];
        memory_capacity = n;
    }
    for(int i = 0; i <n; i++){
        string_content[i] = c[i];
    }
    string_length = n;
    
    return *this;
}
int String::capacity() const{
    return memory_capacity;
}
void String:: reserve(int size){
    if(size > memory_capacity){
        char* prev_starting_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for(int i = 0; i < string_length; i++){
            string_content[i] = prev_starting_content[i];
        }
        delete[] prev_starting_content;
    }

}
char String::at(int i) const {
    if(i >= string_length || i < 0){
        return 0;
    }else{
        return string_content[i];
    }
    
}
String& String::insert(int loc, const String& c){
    //이는 i의 위치 바로 앞에 문자를 삽입하게 된다
    if(loc < 0 || loc > string_length) return *this;

    if(string_length + c.string_length > memory_capacity){
        if(memory_capacity * 2 > string_length + c.string_length){
            memory_capacity *=2;
        }else{
            memory_capacity = string_length + c.string_length;
        }
        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        int i;
        for(i = 0; i < loc; i++){
            string_content[i] = prev_string_content[i];
        }
        for(int j = 0; j < c.string_length; j++){
            string_content[i+j] = c.string_content[j];
        }
        for(; i < string_length; i++){
            string_content[c.string_length + i] = prev_string_content[i];
        }
        delete[] prev_string_content;
        string_length = string_length + c.string_length;
        return *this;
    }
    //만일 초과하지 않는다면 동적할을 할 필요가 없다
    for(int i = string_length-1; i <= loc; i--){
        string_content[i+c.string_length] = string_content[i];
    }
    for(int i = 0; i < c.string_length; i++){
        string_content[i] = c.string_content[i];
    }
    string_length = string_length + c.string_length;
    return *this;
}
String& String::insert(int loc, const char* c){
    String temp(c);
    return insert(loc,c);
}
String& String::insert(int loc, char c){
    String temp(c);
    return insert(loc,c);
}
String& String::erase(int loc, int num){
    //loc의 앞 부터 시작해서 num 문자를 지운다
    if(num < 0 || loc < 0 || loc > string_length) return *this;

    for(int i = loc + num; i < string_length; i++){
        string_content[i-num] = string_content[i];
    }
    string_length -=num;
    return *this;
}


void String::add_string(const String& c){
    string_length = string_length + c.string_length;
    char* temp = new char[string_length];
    strcat(temp,string_content);
    strcat(temp,c.string_content);
    delete[] string_content;
    string_content = new char[string_length];
    strcpy(string_content,temp);
    delete[] temp;
}
void String::print() {
    std::cout <<this->string_content << std::endl;
}

int main () {
    String c("hello");
    String d("World");
    c.add_string(d);
    c.print();
    c.assign("a");
    c.print();
    c.insert(2,"dssadd");
    c.assign(d);

}