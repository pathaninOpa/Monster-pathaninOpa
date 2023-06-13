#include "monster.h"
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

class Thanos {
private:
  int stones;
  int hp; // extra hp;
public:
  /* constructor and destructor */
  Thanos(int = 0, int = 100000);
  ~Thanos(); // cout something

  void snap_finger(monster[], int);
  /* show all hps
  / clear half of monster hp, if stone =6*/
  void operator++(); // increase the stone;
};

 Thanos::Thanos(int a, int b) {
  stones = a;
  hp = b;
}
 Thanos::~Thanos(){
   cout << "Thanos destructor summoned."<<endl;
 }
void Thanos::operator++(){
  stones++;
}


void Thanos::snap_finger(monster m[], int n){
  int i,min =0, max = n;

      if(stones<6){ 
        cout<<"------------------------------------------\n"<<"\"Not enough stones..\" Thanos whispered"<<endl<<"------------------------------------------"<<endl;
        cout << "A fierce combat ensues.."<<endl;
        for(i=0;i<n;i+=2){
            if (i + 1 < n){
              cout << m[i].get_name() << " attacks " << m[i + 1].get_name()                 << "!" << endl;
              m[i].Attack(m[i+1]);
              m[i+1].print();
              cout<<setw(10)<<"|\n"<<setw(9)<<"v"<<endl;
              cout << m[i+1].get_name() << " attacks " << m[i].get_name()                 << "!" << endl;
              m[i+1].Attack(m[i]);
              m[i].print();
              (i != n-1) ? cout<<setw(10)<<"|\n"<<setw(9)<<"v"<<endl : cout<<"";
            }
        }
      }
      else if(stones == 6){
         cout<<"------------------------------------------\n"<<"It is over..Thanos has snapped!!\n"<<"------------------------------------------"<<endl;
        for (i = 0; i < n/2; i++){
          random_device rd;
          mt19937 generator(rd());
          uniform_int_distribution<int> distribution(min, max);
          int rand = distribution(generator);
          m[rand].set_hp(m[rand].get_hp() * 0);
        }
      }
}