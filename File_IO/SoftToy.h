#pragma once
#include "Toy.h"

class SoftToy : public Toy {
private:
    string material;
    int height;

public:
    SoftToy();
    SoftToy(const string& article, const string& name, double price, int minAge, const string& material, int height);

    string get_material() const;
    int get_height() const;

    void set_material(const string& m);
    void set_height(int h);

    string get_type() const override;
    void print(ostream& os) const override;
    void input(istream& is) override;

    void saveToFile(ofstream& ofs) const override;
    void loadFromFile(ifstream& ifs) override;
};