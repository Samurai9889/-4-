#include <iostream>
#include <vector>
#include <string>

class Animal {
public:
    std::string name;

    Animal(const std::string& animalName) : name(animalName) {
        std::cout << "Створений об'єкт Animal з iм'ям: " << name << std::endl;
    }

    virtual ~Animal() {
        std::cout << "Animal деструктор для " << name << std::endl;
    }
};

class Mammal : public Animal {
public:
    Mammal(const std::string& mammalName) : Animal(mammalName) {
        std::cout << "Створений об'єкт Mammal з iм'ям: " << name << std::endl;
    }

    virtual ~Mammal() {
        std::cout << "Mammal деструктор для " << name << std::endl;
    }
};

class Bird : public Animal {
public:
    Bird(const std::string& birdName) : Animal(birdName) {
        std::cout << "Створений об'єкт Bird з iм'ям: " << name << std::endl;
    }

    virtual ~Bird() {
        std::cout << "Bird деструктор для " << name << std::endl;
    }
};

class HoofedMammal : public Mammal {
public:
    HoofedMammal(const std::string& hoofedMammalName) : Mammal(hoofedMammalName) {
        std::cout << "Створений об'єкт HoofedMammal з iм'ям: " << name << std::endl;
    }

    virtual ~HoofedMammal() {
        std::cout << "HoofedMammal деструктор для " << name << std::endl;
    }
};

class Faculty {
private:
    std::vector<Animal*> animals;

public:
    void addAnimal(Animal* animal) {
        animals.push_back(animal);
    }

    void iterateAnimals() {
        for (auto it = animals.begin(); it != animals.end(); ++it) {
            Animal* animal = *it;
            // Виконати дії з кожним об'єктом Animal (або його похідними класами)
            // Наприклад, викликати методи або виконати інші операції
            std::cout << "Iтерація по об'єкту Animal з iм'ям: " << animal->name << std::endl;
        }
    }

    ~Faculty() {
        std::cout << "Faculty деструктор" << std::endl;
        for (auto animal : animals) {
            delete animal;
        }
    }
};

int main() {
    Faculty faculty;
    setlocale(LC_ALL, "");

    // Створення ссавців з ім'ями
    Mammal* mammal1 = new Mammal("Ссавець 1");
    Mammal* mammal2 = new Mammal("Ссавець 2");
    HoofedMammal* hoofedMammal = new HoofedMammal("Парнокопитний 1");

    // Додавання ссавців до факультету
    faculty.addAnimal(mammal1);
    faculty.addAnimal(mammal2);
    faculty.addAnimal(hoofedMammal);

    // Ітерація по об'єктах Animal у факультеті
    faculty.iterateAnimals();

    // Видалення факультету (виклик деструктора)
    return 0;
}