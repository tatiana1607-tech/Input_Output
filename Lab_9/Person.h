#pragma once
#include <string>
#include <iostream>
#include "Exceptions.h"
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person();
    Person(string n, int a);
    Person(const Person& other);
    virtual ~Person();

    string getName() const;
    int getAge() const;
    void setName(string n);
    void setAge(int a);
    virtual void display() const;
    virtual string getType() const = 0;
};