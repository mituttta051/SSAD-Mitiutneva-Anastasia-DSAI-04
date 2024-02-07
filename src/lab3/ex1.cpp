#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    Animal() {
        name = "Base name";
        age = 10;
    }
    virtual void makeSound() = 0;

};

class LandAnimal : public virtual Animal {
public:
    LandAnimal(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void eat() {
        cout << this->name + " is eating" << endl;
    }
    void makeSound() override {
        cout << "Arr" << endl;
    }
};

class WaterAnimal : public virtual Animal {
public:
    WaterAnimal(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void drink() {
        cout << this->name + "is drinking water" << endl;
    }
    void makeSound() override {
        cout << "Bubble-bubble" << endl;
    }
};

class Lion : public LandAnimal {
public:
    Lion(string name, int age) : LandAnimal(name, age) {
        this->name = name;
        this->age = age;
    }
    void eat()  {
        cout << this->name + " is eating meat!" << endl;
    }
    void makeSound() override {
        cout << "Roar" << endl;
    }

};
class Mermaid : public WaterAnimal {
public:
    Mermaid(string name, int age) : WaterAnimal(name, age) {
        this->name = name;
        this->age = age;
    }
    void drink() {
        cout << this->name + " is drinking sea water" << endl;
    }
    void makeSound() override {
        cout << "Hello!" << endl;
    }

};

class Amphibian : public LandAnimal, WaterAnimal {
public:
    Amphibian(string name, int age) : WaterAnimal(name, age), LandAnimal(name, age) {
        this->name = name;
        this->age = age;
    }
    void makeSound() override {
        cout << "Croak" << endl;
    }
};


int main() {
    Animal* animals[3];
    animals[0] = (new Lion("Petya", 13));
    animals[1] = (new Mermaid("Sveta", 18));
    animals[2] = (new Amphibian("Frog", 3));
    for (Animal* animal : animals) {
        animal->makeSound();
        if (Lion* l = dynamic_cast<Lion*>(animal)) {
            l->eat();
        } else if (auto* m = dynamic_cast<Mermaid*>(animal)) {
            m->drink();
        } else if (auto* a = dynamic_cast<Amphibian*>(animal)) {
            a->eat();
        }
        cout << "" << endl;

    }

    return 0;
}
