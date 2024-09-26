#include <iostream>
using namespace std;

class Animal {
  int age;
public:
  Animal(int age) : age(age) {
  }
  virtual void talk() = 0;
};

class Cat : public Animal {
  int lives;
public:
  Cat(int initAge, int initLives) : Animal(initAge) {
    lives = initLives;
  }
  virtual void talk() {
    cout << "I disdain you all" << endl;
  }

};

int main() {
  Cat you(50, 9);
  you.talk();

  Cat* c = &you;
  c->talk();
  Animal* a = &you;
  a->talk();

  Animal& aref = you;
  aref.talk();
}
