#pragma once
#include "Toy.h"

using namespace std;

class Constructor : public Toy {
private:
    int pieces;
    string series;

public:
    Constructor(); 
    Constructor(const string& art, const string& n, double p, int m, int pieces, const string& series); 
    int get_pieces() const;
    string get_series() const;
    void set_pieces(int pc);
    void set_series(const string& s);

    string get_type() const override;
    void print(ostream& os) const override;
    void input(istream& is) override;
};