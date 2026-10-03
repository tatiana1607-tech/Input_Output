#include "Person.h"

Person::Person() : name("Неизвестно"), age(0) {
   
}

Person::Person(string n, int a) : name(n), age(a) {
   
    if (age < 0 || age > 150) {
        throw InvalidInputException("Недопустимый возраст!");
    }
}

Person::Person(const Person& other) : name(other.name), age(other.age) {
   
}

Person::~Person() {
    
}

string Person::getName() const { return name; }
int Person::getAge() const { return age; }
void Person::setName(string n) { name = n; }
void Person::setAge(int a) { age = a; }

void Person::display() const {
    cout << name << " (" << age << " лет)";
}