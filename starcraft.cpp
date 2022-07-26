#include <iostream>

class Marine {
    int hp;                 //마린 체력
    int coord_x, coord_y;   //마린 위치
    int damage;             //공격력
    bool is_dead;           // 생명
    char *name;

    public:
    Marine();               //기본 생성자
    Marine(int x, int y,const char* marine_name);
    int attck();
    void be_attacked(int damage_earn);
    void move(int x, int y);
    void show_status();
    ~Marine();
};
Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y, const char* marine_name){
    name = new char[strlen(marine_name) + 1];
    strcpy(name,marine_name);
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}
int Marine::attck() {
    return damage;
}
void Marine:: be_attacked(int damage_earn){
    hp-=damage_earn;
    if(hp < 0) is_dead = true;
}
void Marine::show_status(){
    std::cout << " " << name << " "<< std::endl;
    std::cout << " Location : (" << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP " << hp << std::endl;

}
Marine::~Marine(){
    std::cout << name << " 의 소멸자 호출! " << std::endl;
    if(name != NULL){
        delete[] name;
    }
}

int main (){
    // Marine marine1(2,3);
    // Marine marine2(3,5);
    // marine1.show_status();
    // marine2.show_status();
    // //마린 1이 마린 2 를 공격
    // marine2.be_attacked(marine1.attck());
    // marine1.show_status();
    // marine2.show_status();

    //마린을 배열로 정렬
    Marine* marines[100];
    marines[0] = new Marine(2,3,"Marine 2");
    marines[1] = new Marine(3,5,"Marine 1");
    marines[0]->show_status();
    marines[1]->show_status();
    //마린 2가 마린 1을 공격
    std::cout << "마린 2 가 마린 1 을 공격!" << std::endl;
    marines[1]->be_attacked(marines[0]->attck());
    marines[0]->show_status();
    marines[1]->show_status();
    delete marines[0];
    delete marines[1];
    
    return 0;
}