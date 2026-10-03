#pragma once
#include "Toy.h"

using namespace std;

class Electronic : public Toy {
private:
    string battery;
    bool hasRemote;

public:
    Electronic(); 
    Electronic(const string& art, const string& n, double p, int m, const string& battery, bool hasRemote); 
    string get_battery() const;
    bool get_hasRemote() const;
    void set_battery(const string& b);
    void set_hasRemote(bool r);

    string get_type() const override;
    void print(ostream& os) const override;
    void input(istream& is) override;
};