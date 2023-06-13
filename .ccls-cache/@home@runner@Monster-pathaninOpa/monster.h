#ifndef monster_h
#define monster_h
#include <iostream>
#include <cstring>
#include <random>
using namespace std;

class monster{
private:
	string name;
	int hp,potion;
public:
  void operator++();
  void operator--();
  void operator+=(int); // += hp
  void Attack(monster &); 
//void heal(); // your idea to help revive hp
  void print(); // to print all data
  bool not_dead() { return hp>0;  }
  int get_hp() { return hp; }
  void set_hp(int new_hp){hp=new_hp;}
  string get_name() {return name;}
  int rand(int min, int max);
monster(string, int=0,int=0);
monster();
//Alt+126
~monster();

};

void monster::operator++(){
  potion++;
}
void monster::operator--(){
  hp--;
}
void monster::operator+=(int value){
  hp += value;
}

void monster::print(){
  cout<<"Monster "<<name;
  if (hp < 0){
    cout<<" hp: 0"<<" potion: "<<potion<<endl;
  }
  else{
    cout<<" hp:"<<hp<<" potion: "<<potion<<endl;
  }
}

void monster::Attack(monster & b){// x.Attack(y)
     cout<<"ATTACK!!!!!"<<endl;
     if(this->hp>0){
        int damage = rand(1, 99);
        if (damage > 44){
          cout<<"Critical Hit"<<endl;
        }
        b.hp-= damage;
     }
  else cout<<"Lemme rest in peace, I am already dead! X("<<endl;
}

monster::~monster(){
  cout << "Monster " << name << " is gone." << endl;
}
monster::monster(){

  cout << "Enter monster name: ";
  cin >> name;
  cout << "Enter monster hp: ";
  cin >> hp;
  cout << "Enter monster potion: ";
  cin >> potion;
  cout<<"monster "<<name <<" is here HAHAHA"<<endl;
}
monster::monster(string n ,int p,int h){

  //set var
  name=n;
  hp=h ;
  potion=p;
  cout<<"monster "<<name <<" is here HAHAHA"<<endl;
  
}
int monster::rand(int min, int max){
          random_device rd;
          mt19937 generator(rd());
          uniform_int_distribution<int> distribution(min, max);
          int rand = distribution(generator);
          return rand;
}



#endif
