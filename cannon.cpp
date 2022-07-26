#include <string.h>
#include <iostream>

class Photon_Cannon {
    int hp,shield;
    int coord_x,coord_y;
    int damage;
    char* dname;
    public:
    Photon_Cannon(int x, int y,const char* name);
    //Photon_Cannon(const Photon_Cannon& pc);

    void show_status();
    ~Photon_Cannon();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc){
    std::cout << "복사 생성자 호출" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
    
    dname = new char[strlen(pc.dname) + 1];//
    strcpy(dname,pc.dname);

}
Photon_Cannon::Photon_Cannon(int x, int y,const char* name){
    std::cout << "생성자 호출 !" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    dname = new char[strlen(name) + 1];
    strcpy(dname,name);
}
void Photon_Cannon::show_status() {
    std::cout << "Cannon" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
Photon_Cannon::~Photon_Cannon(){
    std::cout <<" 소멸자 호출 " << std::endl;
    if(dname){
        delete[] dname;
    }
}

int main () {
    Photon_Cannon pc1(1,2,"Awsome Cannon 1");
    Photon_Cannon pc2 = pc1; // Photon_Cannon pc1(pc2); 과 같은 뜻이다. 
    //Photon_Cannon pc3 = pc1;

    pc1.show_status();
    pc2.show_status();

    return 0;
}
