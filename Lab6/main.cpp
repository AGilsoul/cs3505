#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal {
protected:
    double age; 
    string name;
public:
    Animal(string name) : name(name), age(0) {};
    virtual void speak() {
        cout << "I am an animal named " << name << endl;
    }
    void talk() {
        speak();
    }
};

class Cat : public Animal {
    bool isHouseCat;
public:
    Cat(string catName, bool houseCat): Animal(catName), isHouseCat(houseCat) {};

    virtual void speak() {
        cout << "Meow" << " and I am " << name << " and my housecatness is " << isHouseCat << endl;
    }

};

class Dog: public Animal {
    bool likesFetch;
public:
    Dog(string dogName, bool likesFetch): Animal(dogName), likesFetch(likesFetch) {};

    virtual void speak() {
        cout << "Bark! I am " << name << " and my likes fetchingnesss is " << likesFetch << endl;
    }
};

int main() {
    Animal animal("Simba");
    Cat cat("Stray", false);
    Dog dog("Wolf", true);
    animal.speak();
    cat.speak();
    dog.speak();

    vector<Animal*> animals;
    animals.push_back(&animal);
    animals.push_back(&cat);
    animals.push_back(&dog);
    for (auto animal : animals) {
        animal->speak();
    }

    Animal* testAnimal = &cat;
    cout << "talking" << endl;
    testAnimal->talk();

    return 0;
}