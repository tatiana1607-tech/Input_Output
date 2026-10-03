#pragma once
#include <iostream>
#include <string>

using namespace std;

class Toy {
protected:
    string article;
    string name;
    double price;
    int minAge;

public:
    Toy(); 
    Toy(const string& article, const string& name, double price, int minAge);
    virtual ~Toy();

    string get_article() const;
    string get_name() const;
    double get_price() const;
    int get_minAge() const;

    void set_article(const string& a);
    void set_name(const string& n);
    void set_price(double p);
    void set_minAge(int m);

    virtual string get_type() const = 0;
    virtual void print(ostream& os) const = 0;
    virtual void input(istream& is);

    friend ostream& operator<<(ostream& os, const Toy& t);
    friend istream& operator>>(istream& is, Toy& t);
};

int readInt(istream& is, const string& prompt);
double readDouble(istream& is, const string& prompt);