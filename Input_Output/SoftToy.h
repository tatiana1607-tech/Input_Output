#pragma once
#include "Toy.h"

using namespace std;

class SoftToy : public Toy {
private:
    string material;
    double height;

public:
    SoftToy(); 
    SoftToy(const string& art, const string& n, double p, int m, const string& material, double height); 

 
    string get_material() const;
    double get_height() const;
    void set_material(const string& mat);
    void set_height(double h);

    string get_type() const override;
    void print(ostream& os) const override;
    void input(istream& is) override;
};